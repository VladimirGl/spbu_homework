#ifndef BSORT_H
#define BSORT_H

#include "sorter.h"

/**
 * @file bsort.h
 *
 * @section DESCRIPTION
 *
 * Realization of bubble sort class.
 */

///BSort class.
class BSort : public Sorter
{
public:
    BSort(int *array, int size):
        Sorter(array, size)
    {}

    void sort();
protected:
    ///Bubble sort realization.
    void bubbleSort();
};

#endif // BSORT_H
