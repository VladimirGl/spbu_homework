#include "shell.h"

#include <qmath.h>

Shell::Shell(QGraphicsScene *scene, int angle, int posX, int posY):
    pScene(scene),
    startPosX(posX),
    startPosY(posY),
    size(0.4),
    way(3 / cos((qAbs(angle) * myPi) / 180)),
    direction(angle),
    coordinateX(posX),
    coordinateY(posY),
    item(new QGraphicsPixmapItem(QPixmap("D:/bullet.gif")))
{
    item->scale(size, size);
    pScene->addItem(item);
    item->setPos(posX, posY);
    item->setTransformOriginPoint(25, 6);
    item->setRotation(direction + 180);
}

Shell::~Shell()
{
    delete item;
}

void Shell::changeCoordinates()
{
    coordinateX += 25;
  // тут не так coordinateY -= 25;
}
