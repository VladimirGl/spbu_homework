#ifndef TICTACTOEPLAY_H
#define TICTACTOEPLAY_H

#include <QString>

/**
 * @file ticTacToePay.h
 *
 * Class to play tic-tac.
 */

int const numOfButtons = 9;

class TicTacToePlay
{
public:
    TicTacToePlay():
        isX(true),
        array(new int[numOfButtons])
    {
        for (int i = 0; i < numOfButtons; i++)
        {
            array[i] = 0;
        }
    }

    QString setSign(int num)
    {
        if (array[num] != 0)
            return " ";
        if (isX)
        {
            array[num] = 1;
            step();
            return "X";
        }
        else
        {
            array[num] = -1;
            step();
            return "O";
        }
    }

    void step() { isX = !isX; }
    bool isCross() { return isX; }

    int isWin()
    {
        if ((array[0] == array[1]) && (array[0] == array[2]) && (array[0] != 0))
            return array[0];
        if ((array[3] == array[4]) && (array[3] == array[5]) && (array[3] != 0))
            return array[3];
        if ((array[6] == array[7]) && (array[6] == array[8]) && (array[6] != 0))
            return array[6];
        if ((array[0] == array[3]) && (array[0] == array[6]) && (array[0] != 0))
            return array[0];
        if ((array[1] == array[4]) && (array[1] == array[7]) && (array[1] != 0))
            return array[1];
        if ((array[2] == array[5]) && (array[2] == array[8]) && (array[2] != 0))
            return array[2];
        if ((array[0] == array[1]) && (array[0] == array[2]) && (array[0] != 0))
            return array[0];
        if ((array[0] == array[4]) && (array[0] == array[8]) && (array[0] != 0))
            return array[0];
        if ((array[2] == array[4]) && (array[2] == array[6]) && (array[2] != 0))
            return array[2];
        return 0;
    }

private:
    bool isX;
    int *array;

};

#endif // TICTACTOEPLAY_H
