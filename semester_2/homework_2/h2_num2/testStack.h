#ifndef TESTSTACK_H
#define TESTSTACK_H

#include <QObject>
#include <QtTest/QtTest>

#include "pointerStack.h"
#include "arrayStack.h"

class TestStack : public QObject
{
    Q_OBJECT
public:
    TestStack()
    {}
    
private slots:
    void init()
    {
        pointerStack = new PointerStack;
        arrayStack = new ArrayStack;
    }

    void cleanup()
    {
        delete pointerStack;
        delete arrayStack;
    }

    void testCreate()
    {
    }

    void testPointerIsEmpty()
    {
        QVERIFY(pointerStack->isEmpty());
    }

    void testPointerPush()
    {
        pointerStack->push(5);
        pointerStack->push(7);
    }

    void testPointerTop()
    {
        pointerStack->push(7);
        pointerStack->push(5);
        pointerStack->push(3);
        QVERIFY(pointerStack->top() == 3);
    }

    void testPointerPop()
    {
        pointerStack->push(7);
        pointerStack->push(5);
        pointerStack->push(3);
        QVERIFY(pointerStack->top() == 3);
        pointerStack->pop();
        QVERIFY(pointerStack->top() == 5);
        pointerStack->pop();
        QVERIFY(pointerStack->top() == 7);
        pointerStack->pop();
        QVERIFY(pointerStack->isEmpty());
    }

    void testArrayIsEmpty()
    {
        QVERIFY(arrayStack->isEmpty());
    }

    void testArrayPush()
    {
        arrayStack->push(5);
        arrayStack->push(7);
    }

    void testArrayTop()
    {
        arrayStack->push(7);
        arrayStack->push(5);
        arrayStack->push(3);
        QVERIFY(arrayStack->top() == 3);
    }

    void testArrayPop()
    {
        arrayStack->push(7);
        arrayStack->push(5);
        arrayStack->push(3);
        QVERIFY(arrayStack->top() == 3);
        arrayStack->pop();
        QVERIFY(arrayStack->top() == 5);
        arrayStack->pop();
        QVERIFY(arrayStack->top() == 7);
        arrayStack->pop();
        QVERIFY(arrayStack->isEmpty());
    }

private:
    Stack *pointerStack;
    Stack *arrayStack;
    
};

#endif // TESTSTACK_H
