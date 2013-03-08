#include "bsort.h"

#include <iostream>

void BSort::sort()
{
    bubbleSort();
}

void BSort::bubbleSort()
{
    bool isSorted = false;
    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < arraySize; i++)
            if (inArray[i] > inArray[i + 1])
            {
                std::swap(inArray[i], inArray[i + 1]);
                isSorted = false;
            }
    }
}
