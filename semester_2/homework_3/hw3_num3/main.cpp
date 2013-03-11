#include <QtCore/QCoreApplication>
#include <iostream>
#include <ctime>

#include "matrixsorter.h"

/**
 * @file main.cpp
 * @author  Vladimir Glazachev <glazachev.vladimir@gmail.com>
 *
 * @section DESCRIPTION
 *
 * This is a program, that sorts the columns of matrix of the first element.
 */

int **createMatrix(int width, int height)
{
    int **matrix = new int*[width];
    for (int i = 0; i < width; i++)
        matrix[i] = new int[height];
    return matrix;
}

void fillTheMatrix(int **matrix, int width, int height)
{
    srand(time(0));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            matrix[j][i] = (rand() %90) + 10;
    }
}

int main()
{

    int width = 0;
    int height = 0;
    std::cout << "This is a program, that sorts the columns of matrix of the first element\n"
                 "Enter the width of matrix ";
    std::cin >> width;
    std::cout << "Enter the height of matrix ";
    std::cin >> height;

    int **matrix = createMatrix(width, height);
    fillTheMatrix(matrix, width, height);

    MatrixSorter *object = new MatrixSorter(matrix, width, height);
    std::cout << std::endl << std::endl;
    object->print();
    std::cout << std::endl << std::endl;
    object->sort();
    object->print();

    for (int i = 0; i < width; i++)
        delete[] matrix[i];
    delete[] matrix;

    std::cout << "To exit the program enter the characrer ";
    std::cin >> height;

    return 0;
}
