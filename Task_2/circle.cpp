#include "circle.h"
#include <QPainter>

Circle::Circle(double length) : length(length) {
    brush = QBrush(Qt::green);
}

QRectF Circle::boundingRect() const {
    return QRectF(length, length, length, length);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);
    painter->drawRect(boundingRect());
}

QPointF Circle::massCentre() const {
    QPointF centre(0, 0);
    return sceneTransform().map(centre);
}

double Circle::perimeter() const {
    return 4 * length * scale();
}

double Circle::area() const {
    return length * length * scale() * scale();
}
