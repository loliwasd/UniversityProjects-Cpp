#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QElapsedTimer>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartClicked();
    void onUserTextChanged(const QString &text);
    void updateTimer();

private:
    void loadTextFromFile(const QString &filePath);
    void resetTraining();

    QTextEdit *textDisplay;
    QLineEdit *inputField;
    QPushButton *startBtn;
    QLabel *infoLabel;
    QLabel* timeLeftLabel;


    QString referenceText;
    QTimer *trainingTimer;
    QElapsedTimer startTime;
    int elapsedSeconds;
    int mistakes;
    const int totalTime = 60;
};

#endif // MAINWINDOW_H
