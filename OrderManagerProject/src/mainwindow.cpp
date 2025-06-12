#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    loadTextFilesFromFolder(QDir::currentPath());
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, [=](const QString &filePath) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            ui->textEdit->setPlainText(in.readAll());
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not open file");
        }
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loadOrdersFromFile(const QString& path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл заказов");
        return;
    }
    QTextStream in(&file);
    orderList.clear();
    QString content;
    while (!in.atEnd()) {
        QString line = in.readLine();
        content += line + '\n';
        QStringList parts = line.split(",");
        if (parts.size() >= 3) {
        orderList.append(Order(parts[0], parts[1], parts[2]));
        }
    }
    ui->textEdit->setPlainText(content);
    file.close();
}

void MainWindow::on_loadOrdersBtn_clicked() {
    QString path = QFileDialog::getOpenFileName(this, "Открыть список заказов", "", "Text Files (*.txt)");
    if (!path.isEmpty()) {
        loadOrdersFromFile(path);
        QMessageBox::information(this, "Готово", "Заказы загружены");
    }
}

void MainWindow::on_generateInvoiceBtn_clicked() {
    if (orderList.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Нет заказов для обработки");
        return;
    }

    for (const Order& order : orderList) {
        generateInvoice(order);
    }

    QMessageBox::information(this, "Готово", "Накладные сформированы");
}

void MainWindow::generateInvoice(const Order& order) {
    QString filename = QString("invoice_%1.txt").arg(order.getOrderNumber());
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);
    out << "Номер заказа: " << order.getOrderNumber() << "\n";
    out << "Дата: " << order.getOrderDate() << "\n";
    out << "Заказчик: " << order.getCustomerDetails() << "\n";
    out << "Товары:\n";

    QString parseFileName = order.getOrderNumber() + ".txt";
    QFile parseItems(parseFileName);
    if (!parseItems.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream in(&parseItems);
    QStringList itemCodes;
    double totalCost = 0.0;
    int totalQuantity = 0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 3) {
            QString itemCode = parts[0].trimmed();
            int quantity = parts[1].toInt();
            totalQuantity += quantity;
            double price = parts[2].toDouble();

            double itemTotal = quantity * price;
            totalCost += itemTotal;

           itemCodes.append(itemCode);
        }
    }
    out << itemCodes.join(", ") << "\nTotal items bought: "<< totalQuantity <<"\nTotal price: " << totalCost << " р.\n";
    parseItems.close();
    file.close();
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

void MainWindow::loadTextFilesFromFolder(const QString& folderPath) {
    QDir dir(folderPath);
    QStringList filters;
    filters << "*.txt";
    dir.setNameFilters(filters);

    QStringList fileList = dir.entryList(QDir::Files);

    ui->comboBox->clear();
    for (const QString &file : fileList) {
        ui->comboBox->addItem(dir.absoluteFilePath(file));
    }
}

