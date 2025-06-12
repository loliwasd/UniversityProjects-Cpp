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
#include <QtWidgets/QComboBox>
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
    QPushButton *loadOrdersBtn;
    QPushButton *generateInvoiceBtn;
    QTextEdit *textEdit;
    QPushButton *saveFileBtn;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        loadOrdersBtn = new QPushButton(centralwidget);
        loadOrdersBtn->setObjectName("loadOrdersBtn");
        loadOrdersBtn->setGeometry(QRect(10, 20, 151, 26));
        generateInvoiceBtn = new QPushButton(centralwidget);
        generateInvoiceBtn->setObjectName("generateInvoiceBtn");
        generateInvoiceBtn->setGeometry(QRect(10, 60, 151, 26));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(420, 70, 361, 361));
        saveFileBtn = new QPushButton(centralwidget);
        saveFileBtn->setObjectName("saveFileBtn");
        saveFileBtn->setGeometry(QRect(630, 440, 151, 26));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(420, 20, 86, 26));
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
        loadOrdersBtn->setText(QCoreApplication::translate("MainWindow", "load file", nullptr));
        generateInvoiceBtn->setText(QCoreApplication::translate("MainWindow", "generate report", nullptr));
        saveFileBtn->setText(QCoreApplication::translate("MainWindow", "save file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
