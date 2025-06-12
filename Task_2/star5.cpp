#include "star5.h"

#include <QPainter>
#include <cmath>

Star5::Star5(double outerRadius, double innerRadius) : outerRadius(outerRadius), innerRadius(innerRadius) {
    for (int i = 0; i < 5; ++i) {
        double angle = 2 * M_PI * i / 5.0;
        polygon << QPointF(outerRadius * cos(angle), outerRadius * sin(angle));
        angle += M_PI / 5.0;
        polygon << QPointF(innerRadius * cos(angle), innerRadius * sin(angle));
    }
    brush = QBrush(Qt::yellow);
}

QRectF Star5::boundingRect() const {
    return polygon.boundingRect();
}

void Star5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(brush);
    painter->drawPolygon(polygon);
}

QPointF Star5::massCentre() const {
    QPointF centre(0, 0);
    return sceneTransform().map(centre);
}

double Star5::perimeter() const {
    double perimeter = 0;
    for (int i = 0; i < polygon.size(); ++i) {
        QPointF p1 = polygon.at(i);
        QPointF p2 = polygon.at((i + 1) % polygon.size());
        perimeter += std::sqrt((p2.x() - p1.x()) * (p2.x() - p1.x()) + (p2.y() - p1.y()) * (p2.y() - p1.y()));
    }
    return perimeter * scale();
}

double Star5::area() const {
    double area = 5 * (outerRadius * innerRadius * std::sin(2 * M_PI / 5.0));
    return area * scale() * scale();
}
