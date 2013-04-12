#ifndef AIRGUNBASE_H
#define AIRGUNBASE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class AirGunBase : public QGraphicsPixmapItem
{
public:
    AirGunBase(QGraphicsScene *scene);
    ~AirGunBase();

private:
    double const size;

    QGraphicsPixmapItem *item;
};

#endif // AIRGUNBASE_H
