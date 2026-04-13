#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "hanoi.h"

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
    bool ok;
    int n = ui->lineEdit->text().toInt(&ok);
    if (!ok || n <= 0) {
        QMessageBox::warning(this, "Error", "Enter integer positive number");
        return;
    }

    Hanoi tower(ui->textEdit);
    tower.solve(n, "A", "C", "B");
}

