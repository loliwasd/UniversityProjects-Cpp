#ifndef HEXAGON_H
#define HEXAGON_H

#include <QBrush>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsItem>
#include <QPainter>
#include "figure.h"

class Hexagon : public Figure {
public:
    Hexagon(double radius);
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

#endif // HEXAGON_H
