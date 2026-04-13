#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsItem>
#include <QPainter>
#include "figure.h"

class Figure : public QGraphicsItem
{
public:
    Figure();
    virtual ~Figure() {}
    QRectF boundingRect() const = 0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

    virtual QPointF massCentre() const = 0;
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
};

#endif // FIGURE_H
