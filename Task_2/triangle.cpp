#include "triangle.h"
#include <QPointF>
#include <QPainter>
#include <cmath>

Triangle::Triangle(const QPointF &p1, const QPointF &p2, const QPointF &p3) {
    polygon << p1 << p2 << p3;
    brush = QBrush(Qt::blue);
}

QRectF Triangle::boundingRect() const {
    return polygon.boundingRect();
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(brush);
    painter->drawPolygon(polygon);
}

QPointF Triangle::massCentre() const {
    QPointF centre = (polygon[0] + polygon[1] + polygon[2]) / 3;
    return sceneTransform().map(centre);
}

double Triangle::perimeter() const {
    double side1 = QLineF(polygon[0], polygon[1]).length();
    double side2 = QLineF(polygon[1], polygon[2]).length();
    double side3 = QLineF(polygon[2], polygon[0]).length();
    return (side1 + side2 + side3) * scale();
}

double Triangle::area() const {
    double side1 = QLineF(polygon[0], polygon[1]).length();
    double side2 = QLineF(polygon[1], polygon[2]).length();
    double side3 = QLineF(polygon[2], polygon[0]).length();
    double s = (side1 + side2 + side3) / 2;
    return std::sqrt(s * (s - side1) * (s - side2) * (s - side3)) * scale() * scale();
}
