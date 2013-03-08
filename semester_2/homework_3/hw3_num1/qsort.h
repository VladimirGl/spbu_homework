#ifndef QSORT_H
#define QSORT_H

#include "sorter.h"

class QSort : public Sorter
{
public:
    QSort(int *array, int size):
        Sorter(array, size)
    {}
    void sort();
protected:
    void quickSort(int first, int last);
};

#endif // QSORT_H
