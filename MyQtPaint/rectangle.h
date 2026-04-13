#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QBrush>
#include <QPointF>
#include <QGraphicsItem>
#include <QPainter>
#include "figure.h"

class Rectangle : public Figure {
public:
    Rectangle(double width, double height);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF massCentre() const;
    double perimeter() const;
    double area() const;

private:
    double width;
    double height;
    QBrush brush;
};

#endif // RECTANGLE_H
