#include "romb.h"
#include <QPainter>
#include <cmath>

Romb::Romb(double width, double height) : width(width), height(height) {
    polygon << QPointF(-width / 2, 0) << QPointF(0, -height / 2)<< QPointF(width / 2, 0) << QPointF(0, height / 2);
    brush = QBrush(Qt::cyan);
}

QRectF Romb::boundingRect() const {
    return polygon.boundingRect();
}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(brush);
    painter->drawPolygon(polygon);
}

QPointF Romb::massCentre() const {
    QPointF centre(0, 0);
    return sceneTransform().map(centre);
}

double Romb::perimeter() const {
    return 2 * std::sqrt(width * width + height * height) * scale();
}

double Romb::area() const {
    return width * height * scale() * scale();
}
