#ifndef AIRGUNTURRET_H
#define AIRGUNTURRET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QLabel>
#include <QMovie>

class AirGunTurret : public QGraphicsPixmapItem
{
public:
    AirGunTurret(QGraphicsScene *scene);
    ~AirGunTurret();

    void setAngle(int angle);
    void upgradeBarrelCoordinates();
    void shoot();

private:
    QGraphicsScene *pScene;

    int const rotationCenterLocalX;
    int const rotationCenterLocalY;
    double const size;

    int const rotationCenterAbsoluteX;
    int const rotationCenterAbsoluteY;

    int const gunBarrelLength;

    int barrelX;
    int barrelY;

    int angle;

    QGraphicsPixmapItem *item;
    QLabel *shootGif;
    QMovie *shootMovie;
};

#endif // AIRGUNTURRET_H
