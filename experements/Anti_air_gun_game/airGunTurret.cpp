#include "airGunTurret.h"

#include <qmath.h>

#include "shell.h"

AirGunTurret::AirGunTurret(QGraphicsScene *scene):
    pScene(scene),
    rotationCenterLocalX(70),
    rotationCenterLocalY(31),
    size(0.4),
    rotationCenterAbsoluteX(43),
    rotationCenterAbsoluteY(412),
    gunBarrelLength(128),
    angle(-30),
    item(new QGraphicsPixmapItem(QPixmap("D:/gun.gif"))),
    shootGif(new QLabel()),
    shootMovie(new QMovie("D:/newShoot.gif"))
{
    item->scale(size, size);
    pScene->addItem(item);
    item->setPos(15, 400);
    item->setTransformOriginPoint(QPointF(rotationCenterLocalX, rotationCenterLocalY));
    item->setRotation(angle);
    QPen pen;
    pScene->addEllipse(rotationCenterAbsoluteX, rotationCenterAbsoluteY, 5, 5, pen, QBrush(Qt::red));
  //  scene->addEllipse(155, 348, 5, 5, pen, QBrush(Qt::red));
}

AirGunTurret::~AirGunTurret()
{
    delete item;
    delete shootGif;
    delete shootMovie;
}

void AirGunTurret::setAngle(int angle)
{
    item->setRotation(angle);
    this->angle = angle;
}

void AirGunTurret::upgradeBarrelCoordinates()
{
    double argument = (qAbs(angle) * myPi) / 180;
    barrelX = rotationCenterAbsoluteX + (int)(gunBarrelLength * qCos(argument));
    barrelY = rotationCenterAbsoluteY - (int)(gunBarrelLength * qSin(argument));
}

void AirGunTurret::shoot()
{
    upgradeBarrelCoordinates();
    Shell *shell = new Shell(pScene, angle, barrelX, barrelY);
}
