#include "mainwindow.h"
#include "ui_mainwindow.h"

Widget::Widget()
{
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    view->setFixedSize(500, 500);
}
