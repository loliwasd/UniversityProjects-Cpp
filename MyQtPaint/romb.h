#ifndef ROMB_H
#define ROMB_H

#include <QBrush>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsItem>
#include "figure.h"

class Romb : public Figure {
public:
    Romb(double width, double height);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF massCentre() const;
    double perimeter() const;
    double area() const;

private:
    double width;
    double height;
    QPolygonF polygon;
    QBrush brush;
};
#endif // ROMB_H
