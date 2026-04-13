#include "mainwindow.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), mistakes(0), elapsedSeconds(0) {
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    textDisplay = new QTextEdit(this);
    textDisplay->setReadOnly(true);

    inputField = new QLineEdit(this);
    inputField->setPlaceholderText("Start typing...");
    connect(inputField, &QLineEdit::textChanged, this, &MainWindow::onUserTextChanged);

    startBtn = new QPushButton("Start", this);
    connect(startBtn, &QPushButton::clicked, this, &MainWindow::onStartClicked);

    infoLabel = new QLabel("Mistakes: 0 | WPM: 0", this);

    timeLeftLabel = new QLabel("Time left: 60s", this);

    layout->addWidget(timeLeftLabel);
    layout->addWidget(textDisplay);
    layout->addWidget(inputField);
    layout->addWidget(startBtn);
    layout->addWidget(infoLabel);

    setCentralWidget(central);

    trainingTimer = new QTimer(this);
    connect(trainingTimer, &QTimer::timeout, this, &MainWindow::updateTimer);
}

MainWindow::~MainWindow() {}

void MainWindow::loadTextFromFile(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file.");
        return;
    }

    QTextStream in(&file);
    referenceText = in.readAll();
    file.close();
    textDisplay->setPlainText(referenceText);
}

void MainWindow::onStartClicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open Text File");
    if (filePath.isEmpty())
        return;
    inputField->setEnabled(true);
    loadTextFromFile(filePath);
    resetTraining();
    startTime.start();
    trainingTimer->start(1000);
}

void MainWindow::resetTraining() {
    inputField->clear();
    mistakes = 0;
    elapsedSeconds = 0;
    infoLabel->setText("Mistakes: 0 | WPM: 0");
    textDisplay->setPlainText(referenceText);
}

void MainWindow::onUserTextChanged(const QString &text) {
    QTextCursor cursor(textDisplay->document());
    cursor.select(QTextCursor::Document);
    cursor.removeSelectedText();
    cursor.insertText(referenceText);

    QTextCharFormat correct, wrong;
    correct.setForeground(Qt::green);
    wrong.setForeground(Qt::red);
    static bool made_mistake;

    for (int i = 0; i < text.length() && i < referenceText.length(); ++i) {
        cursor.setPosition(i);
        cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, 1);
        if (text[i] == referenceText[i]) {
            cursor.setCharFormat(correct);
            made_mistake = 0;
        } else {
            cursor.setCharFormat(wrong);
            if (made_mistake == 0) {
                ++mistakes;
                made_mistake = 1;
            }
        }
    }
}

void MainWindow::updateTimer() {
    elapsedSeconds = startTime.elapsed() / 1000;
    int timeRemaining = totalTime - elapsedSeconds;

    if (timeRemaining <= 0) {
        trainingTimer->stop();
        inputField->setEnabled(false);
        timeLeftLabel->setText("Time's up!");
        return;
    }

    timeLeftLabel->setText(QString("Time left: %1s").arg(timeRemaining));

    double words = inputField->text().split(' ', Qt::SkipEmptyParts).count();
    int wpm = static_cast<int>((words * 60.0) / elapsedSeconds);
    infoLabel->setText(QString("Mistakes: %1 | WPM: %2").arg(mistakes).arg(wpm));
}

