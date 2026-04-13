#ifndef OCTAGON_H
#define OCTAGON_H

#include <QBrush>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsItem>
#include <QPainter>
#include "figure.h"

class Octagon : public Figure {
public:
    Octagon(double radius);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF massCentre() const;
    double perimeter() const;
    double area() const;


private:
    double radius;
    QPolygonF polygon;
    QBrush brush;
};

#endif // OCTAGON_H
