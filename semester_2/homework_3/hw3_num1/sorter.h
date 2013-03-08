#ifndef SORTER_H
#define SORTER_H

class Sorter
{
public:
    Sorter(int *array, int size);
    virtual void sort() = 0;
    void print();
    virtual ~Sorter();
protected:
    int *inArray;
    int arraySize;
};

#endif // SORTER_H
