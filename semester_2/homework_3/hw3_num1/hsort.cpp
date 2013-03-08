#include <iostream>

#include "hsort.h"

void HSort::sort()
{
    heapSort();
}

void down(int *array, int pos, int heapSize)
{
    int child = 0;
    int newelem = array[pos];
    while (pos <= heapSize / 2)
    {
        child = 2 * pos;
        if ((child < heapSize) && (array[child] < array[child + 1]))
            child++;
        if (newelem >= array[child])
            break;
        array[pos] = array[child];
        pos = child;
    }
    array[pos] = newelem;
}

void HSort::heapSort()
{
    for (int i = ((arraySize / 2) - 1); i >= 0; --i)
        down(inArray, i, arraySize-1);
    for (int i = (arraySize - 1); i > 0; --i)
    {
        int temp = inArray[i];
        inArray[i] = inArray[0];
        inArray[0] = temp;
        down(inArray, 0, i-1);
    }
}
