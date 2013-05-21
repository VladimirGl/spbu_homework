#ifndef TESTBUBBLESORTER_H
#define TESTBUBBLESORTER_H

#include <QObject>
#include <QtTest/QtTest>
#include <QString>

#include "bubbleSorter.h"

const int arraySize = 10;

class TestBubbleSorter: public QObject
{
    Q_OBJECT

private slots:
    void testSortInt()
    {
        int array[arraySize];
        for (int i = 0; i < arraySize; i++)
            array[i] = qrand() % 25;

        IntCompare compare;
        BubbleSorter<int> sorter;
        sorter.sort(array, arraySize, compare);

        for (int i = 0; i < arraySize - 1; i++)
            QVERIFY(array[i] >= array[i + 1]);
    }

    void testSortString()
    {
        QString array[arraySize] = { "blabla", "jajaja", "ararara", "oolololl", "kekeke",
                                     "dsfgghfd", "aaaaaa", "fdssdf", "qweqwe", "hello"};

        QStringCompare compare;
        BubbleSorter<QString> sorter;
        sorter.sort(array, arraySize, compare);

        for (int i = 0; i < arraySize - 1; i++)
            QVERIFY(!compare(array[i], array[i + 1]));
    }

    void testSortInt3DVector()
    {
        Vector3D array[arraySize];

        Int3DVectorCompare compare;
        BubbleSorter<Vector3D> sorter;
        sorter.sort(array, arraySize, compare);

        for (int i = 0; i < arraySize - 1; i++)
            QVERIFY(!compare(array[i], array[i + 1]));
    }

private:
    class IntCompare
    {
    public:
        bool operator()(const int &a, const int &b) { return a < b; }
    };

    class Vector3D
    {
    public:
        Vector3D()
        {
            for (int i = 0; i < 3; i++)
                array[i] = qrand() % 25;
        }

        qreal module()
        {
            int sum = 0;
            for (int i = 0; i < 3; i++)
                sum = sum + array[i] * array[i];

            return sqrt(sum);
        }
    private:
        int array[3];
    };

    class Int3DVectorCompare
    {
    public:
        bool operator()(Vector3D a, Vector3D b) { return a.module() < b.module(); }

    private:
    };

    class QStringCompare
    {
    public:
        bool operator()(const QString &a, const QString &b) { return (QString::localeAwareCompare(a, b) < 0); }
    };
};

#endif // TESTBUBBLESORTER_H
