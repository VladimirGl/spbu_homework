#include "gameWidget.h"

GameWidget::GameWidget(QWidget *parent) :
    QGraphicsView(parent),
    scene(new QGraphicsScene),
    airGun(new AirGun(scene))
{
    scene->setSceneRect(0, 0, 640, 480);
    setScene(scene);

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer.start(1000 / 33);
}


GameWidget::~GameWidget()
{
    delete airGun;
    delete scene;
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    const int rotateStep = 2;
    switch (event->key())
    {
    case Qt::Key_Up:
    {
        airGun->rotateTurret(-rotateStep);
        break;
    }
    case Qt::Key_Down:
    {
        airGun->rotateTurret(rotateStep);
        break;
    }
    case Qt::Key_Space:
    {
        airGun->shoot();
        break;
    }
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

