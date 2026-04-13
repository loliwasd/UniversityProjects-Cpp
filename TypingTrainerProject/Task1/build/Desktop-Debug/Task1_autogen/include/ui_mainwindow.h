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
    QTextEdit *textDisplay;
    QPushButton *loadTextBtn;
    QPushButton *startBtn;
    QLabel *mistakeLabel;
    QLineEdit *inputField;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textDisplay = new QTextEdit(centralwidget);
        textDisplay->setObjectName("textDisplay");
        textDisplay->setGeometry(QRect(20, 30, 761, 141));
        loadTextBtn = new QPushButton(centralwidget);
        loadTextBtn->setObjectName("loadTextBtn");
        loadTextBtn->setGeometry(QRect(30, 240, 88, 26));
        startBtn = new QPushButton(centralwidget);
        startBtn->setObjectName("startBtn");
        startBtn->setGeometry(QRect(30, 280, 88, 26));
        mistakeLabel = new QLabel(centralwidget);
        mistakeLabel->setObjectName("mistakeLabel");
        mistakeLabel->setGeometry(QRect(40, 400, 181, 18));
        inputField = new QLineEdit(centralwidget);
        inputField->setObjectName("inputField");
        inputField->setGeometry(QRect(300, 300, 113, 26));
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
        loadTextBtn->setText(QCoreApplication::translate("MainWindow", "load", nullptr));
        startBtn->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        mistakeLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
