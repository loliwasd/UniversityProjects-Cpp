#include "plane.h"
#include <QPainter>
#include <QKeyEvent>

Plane::Plane(QWidget *parent) : QWidget(parent), xPos(0), wheelsDeployed(false) {
    setFixedSize(600, 400);
    connect(&timer, &QTimer::timeout, this, &Plane::movePlane);
    timer.start(20);
}

void Plane::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.setBrush(Qt::blue);
    painter.drawRect(xPos, 150, 100, 30);

    painter.setBrush(Qt::darkBlue);
    painter.drawRect(xPos + 20, 160, 60, 10);
    painter.drawRect(xPos - 30, 165, 60, 10);
    painter.drawRect(xPos - 5, 140, 30, 10);
    painter.drawRect(xPos + 80, 152, 20, 10);

    if (wheelsDeployed) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(xPos + 10, 180, 10, 10);
        painter.drawEllipse(xPos + 20, 180, 10, 10);
        painter.drawEllipse(xPos + 70, 180, 10, 10);
        painter.drawEllipse(xPos + 80, 180, 10, 10);
    }
}

void Plane::movePlane() {
    xPos += 5;
    if (xPos > width()) xPos = -100;
    update();
}

void Plane::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
        wheelsDeployed = !wheelsDeployed;
        update();
    }
}
