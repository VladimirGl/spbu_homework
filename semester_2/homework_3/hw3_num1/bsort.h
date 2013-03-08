#ifndef BSORT_H
#define BSORT_H

#include "sorter.h"

class BSort : public Sorter
{
public:
    BSort(int *array, int size):
        Sorter(array, size)
    {}
    void sort();
protected:
    void bubbleSort();
};

#endif // BSORT_H
