#include "octagon.h"

#include <QPainter>
#include <cmath>

Octagon::Octagon(double radius) : radius(radius) {
    double angle = M_PI / 4;
    for (int i = 0; i < 8; ++i) {
        double x = radius * std::cos(i * angle);
        double y = radius * std::sin(i * angle);
        polygon << QPointF(x, y);
    }
    brush = QBrush(Qt::red);
}

QRectF Octagon::boundingRect() const {
    return polygon.boundingRect();
}

void Octagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(brush);
    painter->drawPolygon(polygon);
}

QPointF Octagon::massCentre() const {
    QPointF centre(0, 0);
    return sceneTransform().map(centre);
}

double Octagon::perimeter() const {
    return 6 * radius * scale();
}

double Octagon::area() const {
    return 3 * std::sqrt(3) / 2 * radius * radius * scale() * scale();
}
