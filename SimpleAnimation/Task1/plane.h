#ifndef PLANE_H
#define PLANE_H

#include <QWidget>
#include <QTimer>

class Plane : public QWidget {
    Q_OBJECT

public:
    Plane(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    int xPos;
    bool wheelsDeployed;
    QTimer timer;

private slots:
    void movePlane();
};

#endif
