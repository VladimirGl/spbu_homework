#ifndef TESTSORTER_H
#define TESTSORTER_H

#include <QObject>
#include <QtTest/QtTest>
#include "matrixsorter.h"

class SorterTest : public QObject
{
    Q_OBJECT
public:
    explicit SorterTest(QObject *parent = 0):
        QObject(parent) {}
private slots:
    void init()
    {
        width = 6;
        height = 7;
        matrix = new int*[width];
        for (int i = 0; i < width; i++)
            matrix[i] = new int[height];

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
                matrix[j][i] = (rand() %90) + 10;
        }

        test = new MatrixSorter(matrix, width, height);
    }

    void cleanup()
    {
        delete test;
        for (int i = 0; i < width; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    void testSort()
    {
        test->sort();
    }

private:
    MatrixSorter *test;
    int **matrix;
    int width;
    int height;
};

#endif // TESTSORTER_H
