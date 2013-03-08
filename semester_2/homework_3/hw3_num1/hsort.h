#ifndef HSORT_H
#define HSORT_H

#include "sorter.h"

class HSort : public Sorter
{
public:
    HSort(int *array, int size):
        Sorter(array, size)
    {}
    void sort();
protected:
    void heapSort();
};

#endif // HSORT_H
