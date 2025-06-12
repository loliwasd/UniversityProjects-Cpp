#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QPolygon>
#include <QPushButton>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsRectItem *square;

public:
    Widget();
public slots:

};
#endif // MAINWINDOW_H
