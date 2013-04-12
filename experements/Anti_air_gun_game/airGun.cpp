#include "airGun.h"

AirGun::AirGun(QGraphicsScene *scene) :
    minRotate(-80),
    maxRotate(-10),
    base(new AirGunBase(scene)),
    turret(new AirGunTurret(scene)),
    currentRotation(-30)
{
    turret->setAngle(currentRotation);
}

AirGun::~AirGun()
{
    delete base;
    delete turret;
}

void AirGun::rotateTurret(int step)
{
    if (currentRotation > maxRotate)
        currentRotation = maxRotate;

    if (currentRotation < minRotate)
        currentRotation = minRotate;

    currentRotation += step;
    turret->setAngle(currentRotation);
}

void AirGun::shoot()
{
    turret->shoot();
}
