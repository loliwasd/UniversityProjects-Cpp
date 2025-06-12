#include "mainwindow.h"

#include <QApplication>
#include "plane.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Plane plane;
    plane.show();
    return app.exec();
}
