#ifndef CIRCLE_H
#define CIRCLE_H

#include <QBrush>
#include <QPainter>
#include <QGraphicsItem>
#include "figure.h"

class Circle : public Figure
{
public:
    Circle(double length);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF massCentre() const;
    double perimeter() const;
    double area() const;

private:
    double length;
    QBrush brush;
};

#endif // CIRCLE_H
