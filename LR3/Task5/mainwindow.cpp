#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "task5.h"
#include <QFileDialog>
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
    QString folderPath = QFileDialog::getExistingDirectory(this, "Choode directory");

    if (!folderPath.isEmpty()) {
        int files = 0;
        int folders = 0;

        countFilesAndFolders(folderPath, files, folders);

        QString result = QString("Folders: %1\nFiles: %2").arg(folders).arg(files);
        ui->textEdit->setPlainText(result);
    }
}

