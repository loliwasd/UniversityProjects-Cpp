#include "rectangle.h"
#include <QPainter>

Rectangle::Rectangle(double width, double height) : width(width), height(height) {
    brush = QBrush(Qt::magenta);
}

QRectF Rectangle::boundingRect() const {
    return QRectF(width / 2, height / 2, width, height);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(brush);
    painter->drawRect(boundingRect());
}

QPointF Rectangle::massCentre() const {
    QPointF centre(0, 0);
    return sceneTransform().map(centre);
}

double Rectangle::perimeter() const {
    return 2 * (width + height) * scale();
}

double Rectangle::area() const {
    return width * height * scale() * scale();
}
