#include "square.h"
#include <QPainter>

Square::Square(int radius) : radius(radius) {
    brush = QBrush(Qt::magenta);
}

QRectF Square::boundingRect() const{
    return QRectF(radius,radius,2*radius,2*radius);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(boundingRect());
}

QPointF Square::massCentre() const {
    QPointF centre = QPointF(0, 0);
    return sceneTransform().map(centre);
}

double Square::perimeter() const {
    return 2 * M_PI * radius * scale();
}

double Square::area() const {
    return M_PI * radius * radius * scale() * scale();
}
