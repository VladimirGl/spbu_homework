#include <QGraphicsScene>
#include <QGraphicsView>

#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(-300, -300, 600, 600);
    base = new AirGunBaseImage(scene);
    QGraphicsView view(scene);
    view.show();
}

MainWindow::~MainWindow()
{
    delete base;
}
