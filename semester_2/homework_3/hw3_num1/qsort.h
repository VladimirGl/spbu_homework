#ifndef QSORT_H
#define QSORT_H

#include "sorter.h"

/**
 * @file qsort.h
 *
 * @section DESCRIPTION
 *
 * Realization of quick sort class.
 */

///QSort class.
class QSort : public Sorter
{
public:
    ///Calling the base class constructor.
    QSort(int *array, int size):
        Sorter(array, size)
    {}

    void sort();
protected:
    ///Quick sort realization.
    void quickSort(int first, int last);
};

#endif // QSORT_H
