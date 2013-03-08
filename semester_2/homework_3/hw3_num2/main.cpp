#include <QtCore/QCoreApplication>
#include <iostream>

#include "consoleprint.h"

int main()
{
    int size = 7;
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
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cin.get();
    SpiralPrinter *object = new ConsolePrint(matrix, size);
    object->print();
  //  std::cin.get();
    for (int i = 1; i <= size; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete object;
    return 0;
}
