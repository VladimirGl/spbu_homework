#ifndef TESTTICTAC_H
#define TESTTICTAC_H

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "ticTacToePlay.h"

class TestTicTac : public QObject
{
    Q_OBJECT
public:
    explicit TestTicTac(QObject* parent = 0):
        QObject(parent)
    {}

private slots:
    void init()
    {
        testPlay = new TicTacToePlay;
    }

    void cleanup()
    {
        delete testPlay;
    }

    void testPlayGame()
    {
        testPlay->setSign(0);
        testPlay->setSign(2);
        testPlay->setSign(4);
        testPlay->setSign(5);
        testPlay->setSign(8);

        QVERIFY(testPlay->isWin() == 1);
    }

private:
    TicTacToePlay *testPlay;
};

#endif // TESTTICTAC_H
