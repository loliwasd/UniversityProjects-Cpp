#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "order.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadOrdersBtn_clicked();
    void on_generateInvoiceBtn_clicked();

    void on_saveFileBtn_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Order> orderList;

    void loadOrdersFromFile(const QString& path);
    void generateInvoice(const Order& order);
    void loadTextFilesFromFolder(const QString& folderPath);

};

#endif // MAINWINDOW_H
