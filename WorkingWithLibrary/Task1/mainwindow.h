#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void generateArray();
    void outputArray();
    void heapSort(QVector<int>&);
    void heapify(QVector<int>& , int, int);
    void merge(QVector<int>&, int, int, int);
    void mergeSort(QVector<int>&, int, int);
    void interpolationSort();
    int partition(QVector<int>&, int, int);
    void quickSort(QVector<int>&, int, int);
    int binsearch(int*, int, int);
    QVector<int> array;

private slots:
    void on_heapsortBtn_clicked();

    void on_quicksortBtn_clicked();

    void on_mergesortBtn_clicked();

    void on_searchBtn_clicked();

    void on_inerpolationBtn_clicked();

    void on_medianBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
