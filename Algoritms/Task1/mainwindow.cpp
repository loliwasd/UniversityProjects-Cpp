#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "tobinary.h"

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
    ToBinary converter;
    int input = ui->lineEdit->text().toInt();
    converter.decimalToBinary(input);
    QString binaryResult = converter.out;
    ui->label->setText(binaryResult);
}

