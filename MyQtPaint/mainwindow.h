#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "square.h"
#include "circle.h"
#include "hexagon.h"
#include "rectangle.h"
#include "romb.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
#include "triangle.h"
#include "octagon.h"
#include "figure.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
private slots:
    void addSquare();
    void addCircle();
    void addHexagon();
    void addRectangle();
    void addRomb();
    void addStar5();
    void addStar6();
    void addStar8();
    void addTriangle();
    void addOctagon();
    void Update();
    void updateScale(int sth);
    void Clear();
    void updateRotation(int sth);
    void on_DeleteFigure_clicked();
    void on_moveFigure_clicked();
};
#endif // MAINWINDOW_H
