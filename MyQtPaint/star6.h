#ifndef STAR6_H
#define STAR6_H

#include <QBrush>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsItem>
#include "figure.h"

class Star6 : public Figure {
public:
    Star6(double outerRadius, double innerRadius);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF massCentre() const;
    double perimeter() const;
    double area() const;

private:
    double outerRadius;
    double innerRadius;
    QPolygonF polygon;
    QBrush brush;
};
#endif // STAR6_H
