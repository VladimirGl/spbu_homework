#include <QtGui/QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "gameWidget.h"
#include "airGun.h"

// нужно поменять путь до изображений.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

  /*  QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 640, 480);
    AirGunBase base(scene);
    AirGunTurret turret(scene);
    QGraphicsView view(scene);*/

    GameWidget view;
    view.setFixedSize(642, 482);
    view.show();

    return a.exec();
}
