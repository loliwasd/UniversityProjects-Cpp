#ifndef STAR5_H
#define STAR5_H

#include <QBrush>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsItem>
#include "figure.h"

class Star5 : public Figure {
public:
    Star5(double outerRadius, double innerRadius);

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

#endif // STAR5_H
