#include <QtCore/QCoreApplication>
#include <iostream>

#include "consoleprint.h"
#include "fileprint.h"

int main()
{
    std::cout << "This program print array elements at round it on a spiral, since the center\n"
                 "You can select the type of print (console/file)\n"
                 "Array (N x N), N - odd number\n"
                 "Enter the type of print (consol - 1, file - 2) - ";

    int type = 0;
    std::cin >> type;
    if (!(type == 1 || type == 2)) {
        std::cin.get();
        std::cout << "Bad type!\n";
        return 1;
    }
    std::cout << "Enter the N -";
    int size = 0;
    std::cin >> size;
    if (!(size % 2))
    {
        std::cout << "N is even\n";
        return 2;
    }

    int counter = 10;
    int **matrix = new int*[size];
    for (int i = 1; i <= size; i++)
        matrix[i] = new int[size];
    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size; j++)
        {
            matrix[i][j] = counter;
            counter++;
        }

    std::cout << "\nMatrix:\n";
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    SpiralPrinter *object;
    if (type == 1)
    {
        std::cout << "\nSpiral print:\n";
        object = new ConsolePrint(matrix, size);
    }
    if (type == 2)
    {
        std::cout << "\nPrint in file 'output.txt'\n";
        object = new FilePrint(matrix, size);
    }

    object->print();

    for (int i = 1; i <= size; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete object;
    return 0;
}
