#include "hexagon.h"

#include <QPainter>
#include <cmath>

Hexagon::Hexagon(double radius) : radius(radius) {
    double angle = M_PI / 3;
    for (int i = 0; i < 6; ++i) {
        double x = radius * std::cos(i * angle);
        double y = radius * std::sin(i * angle);
        polygon << QPointF(x, y);
    }
    brush = QBrush(Qt::yellow);
}

QRectF Hexagon::boundingRect() const {
    return polygon.boundingRect();
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(brush);
    painter->drawPolygon(polygon);
}

QPointF Hexagon::massCentre() const {
    QPointF centre(0, 0);
    return sceneTransform().map(centre);
}

double Hexagon::perimeter() const {
    return 6 * radius * scale();
}

double Hexagon::area() const {
    return 3 * std::sqrt(3) / 2 * radius * radius * scale() * scale();
}
