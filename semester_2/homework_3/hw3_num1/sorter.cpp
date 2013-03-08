#include <iostream>

#include "sorter.h"

Sorter::Sorter(int *array, int size)
{
    inArray = new int[size];
    for (int i = 0; i < size; i++)
        inArray[i] = array[i];
    arraySize = size;
}

void Sorter::print()
{
    for (int i = 0; i < arraySize; i++)
        std::cout << inArray[i] << " ";
    std::cout << std::endl;
}

Sorter::~Sorter()
{
    delete[] inArray;
}
