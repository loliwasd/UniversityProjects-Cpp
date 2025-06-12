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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QPushButton *loadBtn;
    QPushButton *saveFileBtn;
    QSpinBox *sizeSpin;
    QDoubleSpinBox *smSizeSpin;
    QComboBox *genderCombo;
    QLineEdit *brandEdit;
    QPushButton *addTextBtn;
    QPushButton *readTextBtn;
    QPushButton *addBinaryBtn;
    QPushButton *readBinaryBtn;
    QCheckBox *waterproofCheck;
    QTextEdit *outputText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 20, 471, 161));
        loadBtn = new QPushButton(centralwidget);
        loadBtn->setObjectName("loadBtn");
        loadBtn->setGeometry(QRect(30, 200, 88, 26));
        saveFileBtn = new QPushButton(centralwidget);
        saveFileBtn->setObjectName("saveFileBtn");
        saveFileBtn->setGeometry(QRect(140, 200, 88, 26));
        sizeSpin = new QSpinBox(centralwidget);
        sizeSpin->setObjectName("sizeSpin");
        sizeSpin->setGeometry(QRect(670, 20, 101, 27));
        smSizeSpin = new QDoubleSpinBox(centralwidget);
        smSizeSpin->setObjectName("smSizeSpin");
        smSizeSpin->setGeometry(QRect(670, 60, 101, 27));
        genderCombo = new QComboBox(centralwidget);
        genderCombo->addItem(QString());
        genderCombo->addItem(QString());
        genderCombo->addItem(QString());
        genderCombo->setObjectName("genderCombo");
        genderCombo->setGeometry(QRect(670, 100, 101, 26));
        brandEdit = new QLineEdit(centralwidget);
        brandEdit->setObjectName("brandEdit");
        brandEdit->setGeometry(QRect(670, 180, 101, 26));
        addTextBtn = new QPushButton(centralwidget);
        addTextBtn->setObjectName("addTextBtn");
        addTextBtn->setGeometry(QRect(670, 230, 101, 26));
        readTextBtn = new QPushButton(centralwidget);
        readTextBtn->setObjectName("readTextBtn");
        readTextBtn->setGeometry(QRect(670, 270, 101, 26));
        addBinaryBtn = new QPushButton(centralwidget);
        addBinaryBtn->setObjectName("addBinaryBtn");
        addBinaryBtn->setGeometry(QRect(670, 320, 101, 26));
        readBinaryBtn = new QPushButton(centralwidget);
        readBinaryBtn->setObjectName("readBinaryBtn");
        readBinaryBtn->setGeometry(QRect(670, 350, 101, 26));
        waterproofCheck = new QCheckBox(centralwidget);
        waterproofCheck->setObjectName("waterproofCheck");
        waterproofCheck->setGeometry(QRect(670, 140, 131, 24));
        outputText = new QTextEdit(centralwidget);
        outputText->setObjectName("outputText");
        outputText->setGeometry(QRect(20, 250, 471, 161));
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
        loadBtn->setText(QCoreApplication::translate("MainWindow", "load", nullptr));
        saveFileBtn->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        genderCombo->setItemText(0, QCoreApplication::translate("MainWindow", "m", nullptr));
        genderCombo->setItemText(1, QCoreApplication::translate("MainWindow", "f", nullptr));
        genderCombo->setItemText(2, QCoreApplication::translate("MainWindow", "o", nullptr));

        addTextBtn->setText(QCoreApplication::translate("MainWindow", "add boots", nullptr));
        readTextBtn->setText(QCoreApplication::translate("MainWindow", "read boots", nullptr));
        addBinaryBtn->setText(QCoreApplication::translate("MainWindow", "add boots bin", nullptr));
        readBinaryBtn->setText(QCoreApplication::translate("MainWindow", "read boots bin", nullptr));
        waterproofCheck->setText(QCoreApplication::translate("MainWindow", "is waterproof", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
