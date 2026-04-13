#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mystring.h"
#include <cstring>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_memcpy_clicked() {
    MyString s1(ui->input1->text().toUtf8().constData());
    MyString s2(ui->input2->text().toUtf8().constData());
    std::memcpy(s1.data(), s2.data(), std::min(s1.length(), s2.length()));
    ui->result->setText(s1.c_str());
}

void MainWindow::on_strcpy_clicked() {
    MyString s1(100);
    std::strcpy(s1.data(), ui->input1->text().toUtf8().constData());
    ui->result->setText(s1.c_str());
}

void MainWindow::on_strlen_clicked() {
    MyString s(ui->input1->text().toUtf8().constData());
    ui->result->setText(QString::number(s.length()));
}

void MainWindow::on_clear_clicked() {
    ui->input1->clear();
    ui->input2->clear();
    ui->result->clear();
}
