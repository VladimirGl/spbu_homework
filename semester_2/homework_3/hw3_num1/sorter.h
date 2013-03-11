#ifndef SORTER_H
#define SORTER_H

/**
 * @file sorter.h
 * @author  Vladimir Glazachev <glazachev.vladimir@gmail.com>
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

    ///Pure virtual function
    virtual void sort() = 0;

    void print();

    ///Virtual distructor
    virtual ~Sorter();
protected:
    int *inArray;
    int arraySize;
};

#endif // SORTER_H
