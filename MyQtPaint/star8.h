#ifndef STAR8_H
#define STAR8_H

#include <QBrush>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsItem>
#include "figure.h"

class Star8 : public Figure {
public:
    Star8(double outerRadius, double innerRadius);

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

#endif // STAR8_H
