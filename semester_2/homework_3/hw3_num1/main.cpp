#include <QtCore/QCoreApplication>
#include <iostream>
#include <ctime>

#include "qsort.h"
#include "hsort.h"
#include "bsort.h"


/**
 * @file main.cpp
 * @author  Vladimir Glazachev <glazachev.vladimir@gmail.com>
 *
 * @section DESCRIPTION
 *
 * This is a program, in that impelented various sorting.
 */


int main()
{
    std::cout << "The various sorting are realized in this program\n\n"
                 "Enter the size of array: ";
    int size = 0;
    std::cin >> size;

    int *array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = (rand() % 99) + 1;

    std::cout << "\nThe array of random numbers (less 100):\n";
    srand(time(0));
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";

    std::cout << std::endl << std::endl;
    Sorter *qsObject = new QSort(array, size);
    Sorter *hpObject = new HSort(array, size);
    Sorter *bbObject = new BSort(array, size);

    qsObject->sort();
    hpObject->sort();
    bbObject->sort();

    std::cout << "Sorted arrays:\n\n";
    std::cout << "Quick sort:\n";
    qsObject->print();

    std::cout << "\nHeap sort:\n";
    hpObject->print();

    std::cout << "\nBubble sort:\n";
    bbObject->print();

    std::cout << "\n\nTo exit the program enter the character ";
    std::cin.get();

    delete qsObject;
    delete hpObject;
    delete bbObject;
    return 0;
}
