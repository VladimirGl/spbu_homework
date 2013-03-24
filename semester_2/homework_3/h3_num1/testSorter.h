#ifndef TESTSORTER_H
#define TESTSORTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "qsort.h"
#include "hsort.h"
#include "bsort.h"

class TestSorter : public QObject
{
    Q_OBJECT
public:
    TestSorter():
        arrSize(15)
    {}

private slots:
    void initTestCase()
    {
        array = new int[arrSize];
        for (int i = 0; i < arrSize; i++)
            array[i] = (rand() % 99) + 1;
        qTest = new QSort(array, arrSize);
        bTest = new BSort(array, arrSize);
        hTest = new HSort(array, arrSize);
    }

    void testQSort()
    {
        qTest->sort();
        int *sortedArray = qTest->returnSortedArray();
        for (int i = 0; i < arrSize - 1; i++)
        {
            QVERIFY(sortedArray[i] <= sortedArray[i + 1]);
        }
        delete[] sortedArray;
    }

    void testBSort()
    {
        bTest->sort();
        int *sortedArray = bTest->returnSortedArray();
        for (int i = 0; i < arrSize - 1; i++)
        {
            QVERIFY(sortedArray[i] <= sortedArray[i + 1]);
        }
        delete[] sortedArray;
    }
    
    void testHSort()
    {
        hTest->sort();
        int *sortedArray = hTest->returnSortedArray();
        for (int i = 0; i < arrSize - 1; i++)
        {
            QVERIFY(sortedArray[i] <= sortedArray[i + 1]);
        }
        delete[] sortedArray;
    }

    void cleanupTestCase()
    {
        delete[] array;
        delete qTest;
        delete bTest;
        delete hTest;
    }

private:
    int const arrSize;
    int *array;
    Sorter *qTest;
    Sorter *bTest;
    Sorter *hTest;
};

#endif // TESTSORTER_H
