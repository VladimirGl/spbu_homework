#ifndef SORTER_H
#define SORTER_H

/**
 * @file sorter.h
 *
 * @section DESCRIPTION
 *
 * Realization of interface of sorting classes.
 */

///Sorterr class interface
class Sorter
{
public:
    ///Constructor, that copied sorted array in object.
    Sorter(int *array, int size);

    virtual void sort() = 0;

    void print();
    int *returnSortedArray();

    virtual ~Sorter();
protected:
    int *inArray;
    int arraySize;
};

#endif // SORTER_H
