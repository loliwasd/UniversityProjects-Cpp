#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cstring>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFromFile(const QString& path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл заказов");
        return;
    }
    QTextStream in(&file);
    QString content;
    while (!in.atEnd()) {
        QString line = in.readLine();
        content += line + '\n';
    }
    ui->textEdit->setPlainText(content);
    file.close();
}

void MainWindow::on_loadBtn_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Открыть список заказов", "", "Text Files (*.txt)");
    if (!path.isEmpty()) {
        loadFromFile(path);
        QMessageBox::information(this, "Готово", "Заказы загружены");
    }
}


void MainWindow::on_saveFileBtn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << ui->textEdit->toPlainText();
            file.close();
        } else {
            qDebug() << "Не удалось сохранить файл:" << file.errorString();
        }
    }
}

Boots MainWindow::getBootsFromInput()
{
    Boots boots;
    boots.size = ui->sizeSpin->value();
    boots.sm_size = ui->smSizeSpin->value();
    boots.isWaterproof = ui->waterproofCheck->isChecked();
    boots.gender = ui->genderCombo->currentText().at(0).toLatin1();

    QString brand = ui->brandEdit->text();
    strncpy(boots.brand, brand.toLatin1().constData(), 10);
    boots.brand[9] = '\0';

    return boots;
}

void MainWindow::displayBoots(const Boots &boots)
{
    QString text = QString("Size: %1 | SM Size: %2 | Waterproof: %3 | Gender: %4 | Brand: %5")
                       .arg(boots.size)
                       .arg(boots.sm_size)
                       .arg(boots.isWaterproof ? "Yes" : "No")
                       .arg(boots.gender)
                       .arg(boots.brand);

    ui->outputText->append(text);
}

void MainWindow::on_addTextBtn_clicked()
{
    Boots boots = getBootsFromInput();

    QFile file(textFileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << boots.size << "|"
               << boots.sm_size << "|"
               << boots.isWaterproof << "|"
               << boots.gender << "|"
               << boots.brand << "\n";
        file.close();

        QMessageBox::information(this, "Success", "Data saved to text file");
    } else {
        QMessageBox::critical(this, "Error", "Cannot open text file");
    }
}


void MainWindow::on_readTextBtn_clicked()
{
    ui->outputText->clear();

    QFile file(textFileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList parts = line.split("|");

            if (parts.size() == 5) {
                Boots boots;
                boots.size = parts[0].toInt();
                boots.sm_size = parts[1].toFloat();
                boots.isWaterproof = parts[2].toInt();
                boots.gender = parts[3].at(0).toLatin1();
                strncpy(boots.brand, parts[4].toLatin1().constData(), 10);

                displayBoots(boots);
            }
        }
        file.close();
    } else {
        QMessageBox::critical(this, "Error", "Cannot read text file");
    }
}


void MainWindow::on_addBinaryBtn_clicked()
{
    Boots boots = getBootsFromInput();

    QFile file(binaryFileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QDataStream stream(&file);
        boots.serialize(stream);
        file.close();

        QMessageBox::information(this, "Success", "Data saved to binary file");
    } else {
        QMessageBox::critical(this, "Error", "Cannot open binary file");
    }
}


void MainWindow::on_readBinaryBtn_clicked()
{
    ui->outputText->clear();

    QFile file(binaryFileName);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream stream(&file);

        while (!stream.atEnd()) {
            Boots boots;
            boots.deserialize(stream);
            displayBoots(boots);
        }
        file.close();
    } else {
        QMessageBox::critical(this, "Error", "Cannot read binary file");
    }
}

