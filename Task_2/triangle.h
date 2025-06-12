#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QBrush>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsItem>
#include "figure.h"

class Triangle : public Figure {
public:
    Triangle(const QPointF &p1, const QPointF &p2, const QPointF &p3);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF massCentre() const;
    double perimeter() const;
    double area() const;

private:
    QPolygonF polygon;
    QBrush brush;
};

#endif // TRIANGLE_H
