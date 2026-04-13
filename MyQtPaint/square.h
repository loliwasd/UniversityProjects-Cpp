#ifndef SQUARE_H
#define SQUARE_H

#include <QBrush>
#include <QPainter>
#include <QGraphicsItem>
#include "figure.h"

class Square : public Figure
{
public:
    Square(int radius);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF massCentre() const;
    double perimeter() const;
    double area() const;

private:
    int radius;
    QBrush brush;
};

#endif // SQUARE_H
