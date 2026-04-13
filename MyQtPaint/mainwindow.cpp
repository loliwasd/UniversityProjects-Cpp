#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0,0,1920,1080,this);
    scene->addRect(scene->sceneRect());
    ui->graphicsView->setScene(scene);

    connect(ui->AddCircle,&QPushButton::clicked,this,&MainWindow::addSquare);
    connect(ui->AddSquare,&QPushButton::clicked,this,&MainWindow::addCircle);
    connect(ui->AddHexagon,&QPushButton::clicked,this,&MainWindow::addHexagon);
    connect(ui->AddRectangle,&QPushButton::clicked,this,&MainWindow::addRectangle);
    connect(ui->AddRomb,&QPushButton::clicked,this,&MainWindow::addRomb);
    connect(ui->AddStar5,&QPushButton::clicked,this,&MainWindow::addStar5);
    connect(ui->AddStar6,&QPushButton::clicked,this,&MainWindow::addStar6);
    connect(ui->AddStar8,&QPushButton::clicked,this,&MainWindow::addStar8);
    connect(ui->AddTriangle,&QPushButton::clicked,this,&MainWindow::addTriangle);
    connect(scene, &QGraphicsScene::selectionChanged, this, &MainWindow::Update);
    connect(ui->Clear,&QPushButton::clicked,this,&MainWindow::Clear);
    connect(ui->Scale,&QSlider::valueChanged,this,&MainWindow::updateScale);
    connect(ui->Rotation,&QSlider::valueChanged,this,&MainWindow::updateRotation);
    connect(ui->AddOctagon,&QPushButton::clicked,this,&MainWindow::addOctagon);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addSquare(){
    Square *square = new Square(100);
    scene->addItem(square);
}

void MainWindow::addCircle(){
    Circle *circle = new Circle(90==100);
    scene->addItem(circle);
}

void MainWindow::addHexagon(){
    Hexagon *hexagon = new Hexagon(100);
    scene->addItem(hexagon);
}

void MainWindow::addRectangle(){
    Rectangle *rectangle = new Rectangle(100,200);
    scene->addItem(rectangle);
}

void MainWindow::addRomb(){
    Romb *romb = new Romb(50,100);
    scene->addItem(romb);
}

void MainWindow::addStar5(){
    Star5 *star5 = new Star5(100,50);
    scene->addItem(star5);
}

void MainWindow::addStar6(){
    Star6 *star6 = new Star6(100,50);
    scene->addItem(star6);
}

void MainWindow::addStar8(){
    Star8 *star8 = new Star8(100,50);
    scene->addItem(star8);
}

void MainWindow::addOctagon(){
    Octagon *octagon = new Octagon(100);
    scene->addItem(octagon);
}

void MainWindow::Clear() {
    scene->clear();
}

void MainWindow::addTriangle(){
    QPointF p1(100, 0);
    QPointF p2(100, 50);
    QPointF p3(0, 0);
    Triangle *triangle = new Triangle(p1, p2, p3);
    scene->addItem(triangle);
}

void MainWindow::updateScale(int sth) {
    double scaleFactor = sth / 50.0;
    QList<QGraphicsItem *> selectedItems = scene->selectedItems();
    if (!selectedItems.isEmpty()) {
        QGraphicsItem *item = selectedItems.last();
        item->setScale(scaleFactor);
    }
    Update();
}

void MainWindow::updateRotation(int sth) {
    QList<QGraphicsItem *> selectedItems = scene->selectedItems();
    if (!selectedItems.isEmpty()) {
        QGraphicsItem *item = selectedItems.last();
        item->setRotation(sth*6.28f);
    }
    Update();
}

void MainWindow::Update() {
    QList<QGraphicsItem *> selectedItems = scene->selectedItems();
    if (!selectedItems.isEmpty()) {
        QGraphicsItem *item = selectedItems.last();
        Figure *figure = dynamic_cast<Figure *>(item);
        if (figure) {
            QPointF massCentre = figure->massCentre();
            double perimeter = figure->perimeter();
            double area = figure->area();
            ui->MassCenter->setText(QString("Mass center: (%1, %2)").arg(massCentre.x()).arg(massCentre.y()));
            ui->Perimeter->setText(QString("Perimeter: %1").arg(perimeter));
            ui->Area->setText(QString("Area: %1").arg(area));
        }
    }
    for (QGraphicsItem *item : selectedItems) {
        double maxZValue = 0;
        for (QGraphicsItem *otherItem : scene->items()) {
            if (otherItem->zValue() > maxZValue) {
                maxZValue = otherItem->zValue();
            }
        }
        item->setZValue(maxZValue + 1);
    }
}

void MainWindow::on_DeleteFigure_clicked()
{
    QList<QGraphicsItem *> selectedItems = scene->selectedItems();
    if (!selectedItems.isEmpty()) {
        QGraphicsItem *item = selectedItems.last();
        scene->removeItem(item);
        delete item;
    }
}


void MainWindow::on_moveFigure_clicked()
{
    QList <QGraphicsItem *> selectedItems = scene->selectedItems();
    if(!selectedItems.isEmpty()){
        QGraphicsItem *item = selectedItems.last();
        item->moveBy(100, 100);
    }
}

