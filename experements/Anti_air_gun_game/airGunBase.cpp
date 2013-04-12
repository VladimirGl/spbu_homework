#include "airGunBase.h"

AirGunBase::AirGunBase(QGraphicsScene *scene):
    size(0.4),
    item(new QGraphicsPixmapItem(QPixmap("D:/base.gif")))
{
    item->scale(size, size);
    scene->addItem(item);
    item->setPos(0, 410);
}

AirGunBase::~AirGunBase()
{
    delete item;
}


