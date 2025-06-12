#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "reverse.h"

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

void MainWindow::on_reverseBtn_clicked()
{
    int n = ui->lineEdit->text().toInt();
    Reverse rev;
    int result = rev.reverseNumber(n, rev.countDigits(n));
    ui->label->setText(QString::number(result));
}

