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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_set1;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_set2;
    QPushButton *pushButton_memcpy;
    QPushButton *pushButton_strtok;
    QPushButton *pushButton_strcpy;
    QPushButton *pushButton_strncpy;
    QPushButton *pushButton_strcmp;
    QPushButton *pushButton_strncat;
    QPushButton *pushButton_strcoll;
    QPushButton *pushButton_strlen;
    QPushButton *pushButton_strcat;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 400));
        MainWindow->setMaximumSize(QSize(800, 400));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 240, 611, 31));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 771, 71));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 100, 771, 64));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lineEdit_3 = new QLineEdit(layoutWidget1);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout_3->addWidget(lineEdit_3);

        pushButton_set1 = new QPushButton(layoutWidget1);
        pushButton_set1->setObjectName("pushButton_set1");
        sizePolicy.setHeightForWidth(pushButton_set1->sizePolicy().hasHeightForWidth());
        pushButton_set1->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_set1);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lineEdit_4 = new QLineEdit(layoutWidget1);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout_4->addWidget(lineEdit_4);

        pushButton_set2 = new QPushButton(layoutWidget1);
        pushButton_set2->setObjectName("pushButton_set2");
        sizePolicy.setHeightForWidth(pushButton_set2->sizePolicy().hasHeightForWidth());
        pushButton_set2->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(pushButton_set2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        pushButton_memcpy = new QPushButton(centralwidget);
        pushButton_memcpy->setObjectName("pushButton_memcpy");
        pushButton_memcpy->setGeometry(QRect(260, 210, 111, 26));
        pushButton_strtok = new QPushButton(centralwidget);
        pushButton_strtok->setObjectName("pushButton_strtok");
        pushButton_strtok->setGeometry(QRect(380, 240, 121, 26));
        pushButton_strcpy = new QPushButton(centralwidget);
        pushButton_strcpy->setObjectName("pushButton_strcpy");
        pushButton_strcpy->setGeometry(QRect(130, 210, 121, 26));
        pushButton_strncpy = new QPushButton(centralwidget);
        pushButton_strncpy->setObjectName("pushButton_strncpy");
        pushButton_strncpy->setGeometry(QRect(260, 180, 111, 26));
        pushButton_strcmp = new QPushButton(centralwidget);
        pushButton_strcmp->setObjectName("pushButton_strcmp");
        pushButton_strcmp->setGeometry(QRect(130, 180, 121, 26));
        pushButton_strncat = new QPushButton(centralwidget);
        pushButton_strncat->setObjectName("pushButton_strncat");
        pushButton_strncat->setGeometry(QRect(380, 180, 121, 26));
        pushButton_strcoll = new QPushButton(centralwidget);
        pushButton_strcoll->setObjectName("pushButton_strcoll");
        pushButton_strcoll->setGeometry(QRect(10, 210, 111, 26));
        pushButton_strlen = new QPushButton(centralwidget);
        pushButton_strlen->setObjectName("pushButton_strlen");
        pushButton_strlen->setGeometry(QRect(10, 180, 111, 26));
        pushButton_strcat = new QPushButton(centralwidget);
        pushButton_strcat->setObjectName("pushButton_strcat");
        pushButton_strcat->setGeometry(QRect(380, 210, 121, 26));
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Task 2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>S2 is source S1 is destination</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "String 1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "String 2", nullptr));
        pushButton_set1->setText(QCoreApplication::translate("MainWindow", "set #1", nullptr));
        pushButton_set2->setText(QCoreApplication::translate("MainWindow", "set #2", nullptr));
        pushButton_memcpy->setText(QCoreApplication::translate("MainWindow", "memcpy", nullptr));
        pushButton_strtok->setText(QCoreApplication::translate("MainWindow", "strtok", nullptr));
        pushButton_strcpy->setText(QCoreApplication::translate("MainWindow", "strcpy", nullptr));
        pushButton_strncpy->setText(QCoreApplication::translate("MainWindow", "strncpy", nullptr));
        pushButton_strcmp->setText(QCoreApplication::translate("MainWindow", "strcmp", nullptr));
        pushButton_strncat->setText(QCoreApplication::translate("MainWindow", "strncat", nullptr));
        pushButton_strcoll->setText(QCoreApplication::translate("MainWindow", "strcoll", nullptr));
        pushButton_strlen->setText(QCoreApplication::translate("MainWindow", "strlen", nullptr));
        pushButton_strcat->setText(QCoreApplication::translate("MainWindow", "strcat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
