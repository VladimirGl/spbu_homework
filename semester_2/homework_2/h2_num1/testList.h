#ifndef TESTLIST_H
#define TESTLIST_H

#include <QObject>
#include <QtTest/QtTest>

#include "listArray.h"
#include "listPointer.h"

class TestList : public QObject
{
    Q_OBJECT
public:
    explicit TestList(QObject *parent = 0):
        QObject(parent) {}
private slots:
    void init()
    {
        lTest = new PointerList;
        aTest = new ArrayList;
    }

    void cleanup()
    {
        delete lTest;
        delete aTest;
    }

    void testPointerIsEmpty()
    {
        QVERIFY(lTest->isEmpty());
    }

    void testPointerAdd()
    {
        for (int i = 1; i <= 10; i++)
            lTest->addValueInPos(i, i);
    }

    void testPointerIsContained()
    {
        QVERIFY(!lTest->isContained(5));
        for (int i = 1; i <= 10; i++)
            lTest->addValueInPos(i, i);
        QVERIFY(lTest->isContained(5));
        QVERIFY(lTest->isContained(3));
    }

    void testPointerRemove()
    {
        lTest->addValueInPos(5, 3);
        lTest->addValueInPos(3, 4);
        lTest->addValueInPos(1, 2);
        QVERIFY(lTest->isContained(5));
        QVERIFY(lTest->isContained(3));
        lTest->removeValue(3);
        lTest->removeValue(5);
        QVERIFY(!lTest->isContained(5));
        QVERIFY(!lTest->isContained(3));
    }

    void testArrayIsEmpty()
    {
        QVERIFY(aTest->isEmpty());
    }


    void testArrayAdd()
    {
        for (int i = 1; i <= 10; i++) {
            aTest->addValueInPos(i, (11 - i));
        }
    }

    void testArrayIsContained()
    {
        QVERIFY(!aTest->isContained(5));
        for (int i = 1; i <= 10; i++) {
            aTest->addValueInPos(i, (11 - i));
        }
        QVERIFY(aTest->isContained(5));
        QVERIFY(aTest->isContained(3));
    }

    void testArrayRemove()
    {
        aTest->addValueInPos(5, 3);
        aTest->addValueInPos(3, 4);
        aTest->addValueInPos(1, 2);
        QVERIFY(aTest->isContained(5));
        QVERIFY(aTest->isContained(3));
        aTest->removeValue(3);
        aTest->removeValue(5);
        QVERIFY(!aTest->isContained(5));
        QVERIFY(!aTest->isContained(3));
    }

private:
    List *lTest;
    List *aTest;
};

#endif // TESTLIST_H
