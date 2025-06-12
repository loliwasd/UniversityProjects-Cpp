#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QVector<int> array;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateArray()
{
    array.clear();
    QString input_text_edit = ui->textEdit->toPlainText();
    QStringList splited_input = input_text_edit.split(" ", Qt::SkipEmptyParts);
    bool ok;

    for (int i = 0; i < splited_input.length() ; ++i)
    {
        array.append(splited_input[i].toInt());
    }
}

void MainWindow::outputArray()
{
    ui->textEdit_2->clear();
    QString output;
    for (int num : array)
    {
        output += QString::number(num) + " ";
    }
    ui->textEdit_2->setPlainText(output.trimmed());
}

void MainWindow::on_heapsortBtn_clicked()
{
    generateArray();
    QElapsedTimer timer;
    timer.start();
    heapSort(array);
    qint64 timeTaken = timer.nsecsElapsed();
    outputArray();
    ui->textEdit_2->append("Heap Sort Time: " + QString::number(timeTaken / 1e6) + " ms");
}

void MainWindow::on_quicksortBtn_clicked()
{
    generateArray();
    QElapsedTimer timer;
    timer.start();
    quickSort(array, 0, array.size() - 1);
    qint64 timeTaken = timer.nsecsElapsed();
    outputArray();
    ui->textEdit_2->append("Quick Sort Time: " + QString::number(timeTaken / 1e6) + " ms");
}

void MainWindow::on_mergesortBtn_clicked()
{
    generateArray();
    QElapsedTimer timer;
    timer.start();
    mergeSort(array, 0, array.size() - 1);
    qint64 timeTaken = timer.nsecsElapsed();
    outputArray();
    ui->textEdit_2->append("Merge Sort Time: " + QString::number(timeTaken / 1e6) + " ms");
}

void MainWindow::heapify(QVector<int>& array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        std::swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

void MainWindow::heapSort(QVector<int>& array) {
    int n = array.size();

    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(array, n, i);

    for (int i = n - 1; i > 0; --i) {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void MainWindow::merge(QVector<int>& array, int left, int mid, int right) {
    QVector<int> leftArr(array.begin() + left, array.begin() + mid + 1);
    QVector<int> rightArr(array.begin() + mid + 1, array.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j])
            array[k++] = leftArr[i++];
        else
            array[k++] = rightArr[j++];
    }

    while (i < leftArr.size()) array[k++] = leftArr[i++];
    while (j < rightArr.size()) array[k++] = rightArr[j++];
}

void MainWindow::mergeSort(QVector<int>& array, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int MainWindow::partition(QVector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (array[j] < pivot) {
            ++i;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return i + 1;
}

void MainWindow::quickSort(QVector<int>& array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int MainWindow::binsearch(int* arr, int size, int digit) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == digit) {
            return mid;
        } else if (arr[mid] < digit) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void MainWindow::on_searchBtn_clicked()
{
    bool ok;
    int digit = ui->lineEdit->text().toInt(&ok);

    if (!ok) {
        ui->output_lable->setText("Incorrect input");
        return;
    }

    int index = binsearch(array.data(), array.size(), digit);
    ui->output_lable->setText(QString::number(index));
}


void MainWindow::on_inerpolationBtn_clicked()
{

    generateArray();
    QElapsedTimer timer;
    timer.start();
    interpolationSort();
    qint64 timeTaken = timer.nsecsElapsed();
}

void MainWindow::interpolationSort()
{
    QString output;
    int n = array.size();
    if (n <= 1) return;
    for (int i = 1; i < n; ++i)
    {
        output.clear();
        for (int num : array)
        {
            output += QString::number(num) + " ";
        }
        ui->textEdit_2->append(output.trimmed());
        int key = array[i];
        int low = 0;
        int high = i - 1;
        int insertion_pos = i;

        if (high >= low && key >= array[low] && key <= array[high] && array[high] != array[low])
        {
            long long range_diff = static_cast<long long>(array[high]) - array[low];
            long long index_diff = high - low;
            long long value_diff = static_cast<long long>(key) - array[low];

            int probe = low + static_cast<int>((value_diff * index_diff) / range_diff);

            if (array[probe] == key) {
                insertion_pos = probe;
                while (insertion_pos <= high && array[insertion_pos] == key) {
                    insertion_pos++;
                }
            } else if (array[probe] < key) {
                insertion_pos = probe + 1;
                while(insertion_pos <= high && array[insertion_pos] < key) {
                    insertion_pos++;
                }
            } else {
                insertion_pos = probe;
                while (insertion_pos > low && array[insertion_pos - 1] > key) {
                    insertion_pos--;
                }
            }
        }
        else if (high >= low && key < array[low])
        {
            insertion_pos = low;
        }
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        insertion_pos = j + 1;

        if (insertion_pos != i) {
            array[insertion_pos] = key;
        }
    }
}

void MainWindow::on_medianBtn_clicked()
{
    generateArray();
    QVector<int> median;
    int size = array.size();

    for (int i = 0; i < size/3; ++i)
    {
        median.append(array[3*i + 1]);
    }
    if (size%3 == 2)
    {
        median.append((array[size-1] + array[size-2])/2);
    }
    else if(size%3 == 1)
    {
        median.append(array[size -1]);
    }
    ui->textEdit_2->clear();
    QString output;
    for (int num : median)
    {
        output += QString::number(num) + " ";
    }
    ui->textEdit_2->setPlainText(output.trimmed());
}

