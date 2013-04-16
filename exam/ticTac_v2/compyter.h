#ifndef COMPYTER_H
#define COMPYTER_H

#include <QTime>

#include "ticTacToePlay.h"

/// @class Compyter Very styped compyter player.
class Compyter : public TicTacToePlay
{
public:
    Compyter()
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        TicTacToePlay();
    }

    int doStep()
    {
        if (counter == 9)
            return 4;
        int step = qrand() % 9;
        while (array[step] != 0)
            step = qrand() % 9;

       return step;
    }
};

#endif // COMPYTER_H
