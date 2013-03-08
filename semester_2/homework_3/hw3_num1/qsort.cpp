#include <iostream>

#include "qsort.h"

void QSort::sort()
{
    int const first = 0;
    int const last = arraySize - 1;
    quickSort(first, last);
}

void QSort::quickSort(int first, int last)
{
    int middle = inArray[first + (last - first)/ 2];
    int left = first;
    int right = last;
    while (left <= right)
    {
        while (inArray[left] < middle)
        {
            left++;
        }
        while (inArray[right] > middle)
        {
            right--;
        }
        if (left <= right)
        {
            std::swap(inArray[left], inArray[right]);
            left++;
            right--;
        }
    }
    if (left < last)
    {
        quickSort(left, last);
    }
    if (first < right)
    {
        quickSort(first, right);
    }
}
