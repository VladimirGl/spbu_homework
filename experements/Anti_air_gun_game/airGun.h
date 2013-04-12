#ifndef TURRET_H
#define TURRET_H

#include <QGraphicsItem>

#include "airGunBase.h"
#include "airGunTurret.h"

class AirGun
{
public:
    AirGun(QGraphicsScene *scene);
    ~AirGun();

    void rotateTurret(int step);
    void shoot();

protected:
    AirGunBase *base;
    AirGunTurret *turret;
    int currentRotation;

    int const maxRotate;
    int const minRotate;
};

#endif // TURRET_H
