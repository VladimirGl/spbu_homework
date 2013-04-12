#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>

#include "airGun.h"

class GameWidget : public QGraphicsView
{
    Q_OBJECT
public:
    GameWidget(QWidget *parent = 0);
    ~GameWidget();
    
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QGraphicsScene *scene;
    AirGun *airGun;
};

#endif // GAMEWIDGET_H
