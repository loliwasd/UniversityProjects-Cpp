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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *AddCircle;
    QPushButton *AddSquare;
    QPushButton *AddHexagon;
    QPushButton *AddRectangle;
    QPushButton *AddRomb;
    QPushButton *AddStar5;
    QPushButton *AddStar6;
    QPushButton *AddStar8;
    QPushButton *AddTriangle;
    QLabel *MassCenter;
    QLabel *Perimeter;
    QLabel *Area;
    QPushButton *Clear;
    QSlider *Scale;
    QScrollBar *Rotation;
    QPushButton *DeleteFigure;
    QPushButton *moveFigure;
    QPushButton *AddOctagon;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1248, 710);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(160, -10, 781, 561));
        AddCircle = new QPushButton(centralwidget);
        AddCircle->setObjectName("AddCircle");
        AddCircle->setGeometry(QRect(40, 60, 88, 51));
        AddSquare = new QPushButton(centralwidget);
        AddSquare->setObjectName("AddSquare");
        AddSquare->setGeometry(QRect(40, 0, 88, 51));
        AddHexagon = new QPushButton(centralwidget);
        AddHexagon->setObjectName("AddHexagon");
        AddHexagon->setGeometry(QRect(40, 300, 88, 51));
        AddRectangle = new QPushButton(centralwidget);
        AddRectangle->setObjectName("AddRectangle");
        AddRectangle->setGeometry(QRect(40, 120, 88, 51));
        AddRomb = new QPushButton(centralwidget);
        AddRomb->setObjectName("AddRomb");
        AddRomb->setGeometry(QRect(40, 180, 88, 51));
        AddStar5 = new QPushButton(centralwidget);
        AddStar5->setObjectName("AddStar5");
        AddStar5->setGeometry(QRect(40, 410, 88, 41));
        AddStar6 = new QPushButton(centralwidget);
        AddStar6->setObjectName("AddStar6");
        AddStar6->setGeometry(QRect(40, 460, 88, 41));
        AddStar8 = new QPushButton(centralwidget);
        AddStar8->setObjectName("AddStar8");
        AddStar8->setGeometry(QRect(40, 510, 88, 41));
        AddTriangle = new QPushButton(centralwidget);
        AddTriangle->setObjectName("AddTriangle");
        AddTriangle->setGeometry(QRect(40, 240, 88, 51));
        MassCenter = new QLabel(centralwidget);
        MassCenter->setObjectName("MassCenter");
        MassCenter->setGeometry(QRect(140, 580, 151, 71));
        Perimeter = new QLabel(centralwidget);
        Perimeter->setObjectName("Perimeter");
        Perimeter->setGeometry(QRect(430, 580, 161, 71));
        Area = new QLabel(centralwidget);
        Area->setObjectName("Area");
        Area->setGeometry(QRect(690, 570, 171, 91));
        Clear = new QPushButton(centralwidget);
        Clear->setObjectName("Clear");
        Clear->setGeometry(QRect(970, 0, 151, 26));
        Scale = new QSlider(centralwidget);
        Scale->setObjectName("Scale");
        Scale->setGeometry(QRect(1120, 130, 16, 160));
        Scale->setOrientation(Qt::Vertical);
        Rotation = new QScrollBar(centralwidget);
        Rotation->setObjectName("Rotation");
        Rotation->setGeometry(QRect(1010, 130, 16, 160));
        Rotation->setOrientation(Qt::Vertical);
        DeleteFigure = new QPushButton(centralwidget);
        DeleteFigure->setObjectName("DeleteFigure");
        DeleteFigure->setGeometry(QRect(970, 60, 161, 31));
        moveFigure = new QPushButton(centralwidget);
        moveFigure->setObjectName("moveFigure");
        moveFigure->setGeometry(QRect(970, 30, 151, 26));
        AddOctagon = new QPushButton(centralwidget);
        AddOctagon->setObjectName("AddOctagon");
        AddOctagon->setGeometry(QRect(40, 360, 88, 41));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(970, 300, 101, 18));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1090, 300, 101, 18));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1248, 23));
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
        AddCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        AddSquare->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        AddHexagon->setText(QCoreApplication::translate("MainWindow", "Hexagon", nullptr));
        AddRectangle->setText(QCoreApplication::translate("MainWindow", "Recktangle", nullptr));
        AddRomb->setText(QCoreApplication::translate("MainWindow", "Rombus", nullptr));
        AddStar5->setText(QCoreApplication::translate("MainWindow", "Star (5)", nullptr));
        AddStar6->setText(QCoreApplication::translate("MainWindow", "Star (6)", nullptr));
        AddStar8->setText(QCoreApplication::translate("MainWindow", "Star (8)", nullptr));
        AddTriangle->setText(QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        MassCenter->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Perimeter->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Area->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "CLEAR SCENE", nullptr));
        DeleteFigure->setText(QCoreApplication::translate("MainWindow", "DELETE SELECTED", nullptr));
        moveFigure->setText(QCoreApplication::translate("MainWindow", "MOVE FIGURE", nullptr));
        AddOctagon->setText(QCoreApplication::translate("MainWindow", "Octagon", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Rotate figure", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Scale figure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
