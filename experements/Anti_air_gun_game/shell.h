#ifndef SHELL_H
#define SHELL_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QtGui>
#include <QObject>

// Надо изменить стартовые координаты.
// Переделать в простой Item.
// Научить летать.

double const myPi = 3.14159265359;

class Shell : public QGraphicsPixmapItem
{
public:
    Shell(QGraphicsScene *scene, int angle, int posX, int posY);
    ~Shell();

protected:
    void changeCoordinates();

private:
    QGraphicsScene *pScene;

    int const startPosX;
    int const startPosY;

    double const size;
    double const way;

    int  const direction;

    int coordinateX;
    int coordinateY;

    QGraphicsPixmapItem *item;
};

#endif // SHELL_H
