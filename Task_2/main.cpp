#include "mainwindow.h"

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
