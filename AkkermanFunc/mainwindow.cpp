#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "ackermann.h"
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

void MainWindow::on_pushButton_clicked()
{
    try {
        bool ok1, ok2;
        int m = ui->lineEdit->text().toInt(&ok1);
        int n = ui->lineEdit_2->text().toInt(&ok2);

        if (!ok1 || !ok2) {
            throw std::invalid_argument("Введите корректные целые числа.");
        }
        if (m < 0 || n < 0) {
            throw std::invalid_argument("Числа должны быть неотрицательными.");
        }
        if (m > 3 || n > 10) {
            throw std::overflow_error("Значения слишком большие. Возможен выход за пределы стека.");
        }

        Ackermann ack;
        unsigned int result = ack.ackermannFunc(m, n);
        ui->label->setText("Результат: " + QString::number(result));
    } catch (const std::invalid_argument& e) {
        QMessageBox::warning(this, "Ошибка ввода", e.what());
    } catch (const std::overflow_error& e) {
        QMessageBox::warning(this, "Ошибка переполнения", e.what());
    } catch (...) {
        QMessageBox::critical(this, "Неизвестная ошибка", "Произошла непредвиденная ошибка.");
    }
}

