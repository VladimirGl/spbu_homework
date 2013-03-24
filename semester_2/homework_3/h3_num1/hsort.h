#ifndef HSORT_H
#define HSORT_H

#include "sorter.h"

/**
 * @file hsort.h
 *
 * @section DESCRIPTION
 *
 * Realization of heap sort class.
 */

///HSort class.
class HSort : public Sorter
{
public:
    HSort(int *array, int size):
        Sorter(array, size)
    {}

    void sort();
protected:
    ///Heap sort realization.
    void heapSort();
};

#endif // HSORT_H
