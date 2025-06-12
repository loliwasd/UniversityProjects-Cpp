#include "star6.h"
#include <QPainter>
#include <cmath>

Star6::Star6(double outerRadius, double innerRadius) : outerRadius(outerRadius), innerRadius(innerRadius) {
    for (int i = 0; i < 6; ++i) {
        double angle = 2 * M_PI * i / 6.0;
        polygon << QPointF(outerRadius * cos(angle), outerRadius * sin(angle));
        angle += M_PI / 6.0;
        polygon << QPointF(innerRadius * cos(angle), innerRadius * sin(angle));
    }
    brush = QBrush(Qt::cyan);
}

QRectF Star6::boundingRect() const {
    return polygon.boundingRect();
}

void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(brush);
    painter->drawPolygon(polygon);
}

QPointF Star6::massCentre() const {
    QPointF centre(0, 0);
    return sceneTransform().map(centre);
}

double Star6::perimeter() const {
    double perimeter = 0;
    for (int i = 0; i < polygon.size(); ++i) {
        QPointF p1 = polygon.at(i);
        QPointF p2 = polygon.at((i + 1) % polygon.size());
        perimeter += std::sqrt((p2.x() - p1.x()) * (p2.x() - p1.x()) + (p2.y() - p1.y()) * (p2.y() - p1.y()));
    }
    return perimeter * scale();
}

double Star6::area() const {
    double area = 6 * (outerRadius * innerRadius * std::sin(2 * M_PI / 6.0));
    return area * scale() * scale();
}
