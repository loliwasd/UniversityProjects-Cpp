/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *heapsortBtn;
    QTextEdit *textEdit;
    QPushButton *quicksortBtn;
    QPushButton *mergesortBtn;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *output_lable;
    QPushButton *searchBtn;
    QLabel *label_4;
    QTextEdit *textEdit_2;
    QPushButton *inerpolationBtn;
    QPushButton *medianBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        heapsortBtn = new QPushButton(centralwidget);
        heapsortBtn->setObjectName("heapsortBtn");
        heapsortBtn->setGeometry(QRect(50, 210, 151, 26));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(40, 80, 741, 111));
        quicksortBtn = new QPushButton(centralwidget);
        quicksortBtn->setObjectName("quicksortBtn");
        quicksortBtn->setGeometry(QRect(50, 250, 151, 26));
        mergesortBtn = new QPushButton(centralwidget);
        mergesortBtn->setObjectName("mergesortBtn");
        mergesortBtn->setGeometry(QRect(50, 290, 151, 26));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(650, 220, 113, 26));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(480, 220, 171, 18));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(480, 310, 201, 18));
        output_lable = new QLabel(centralwidget);
        output_lable->setObjectName("output_lable");
        output_lable->setGeometry(QRect(680, 310, 66, 18));
        searchBtn = new QPushButton(centralwidget);
        searchBtn->setObjectName("searchBtn");
        searchBtn->setGeometry(QRect(660, 250, 88, 26));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 40, 371, 18));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(50, 410, 711, 151));
        inerpolationBtn = new QPushButton(centralwidget);
        inerpolationBtn->setObjectName("inerpolationBtn");
        inerpolationBtn->setGeometry(QRect(50, 330, 151, 26));
        medianBtn = new QPushButton(centralwidget);
        medianBtn->setObjectName("medianBtn");
        medianBtn->setGeometry(QRect(50, 370, 151, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        heapsortBtn->setText(QCoreApplication::translate("MainWindow", "Heap sort", nullptr));
        quicksortBtn->setText(QCoreApplication::translate("MainWindow", "Quick sort", nullptr));
        mergesortBtn->setText(QCoreApplication::translate("MainWindow", "Merge sort", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter number to search", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Index of this number in array:", nullptr));
        output_lable->setText(QCoreApplication::translate("MainWindow", "---", nullptr));
        searchBtn->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Enter numbers with Space in between to form an array", nullptr));
        inerpolationBtn->setText(QCoreApplication::translate("MainWindow", "Interpolation sort", nullptr));
        medianBtn->setText(QCoreApplication::translate("MainWindow", "Median", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
