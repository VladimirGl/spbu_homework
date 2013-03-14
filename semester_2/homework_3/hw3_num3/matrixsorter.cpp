#include <iostream>

#include "matrixsorter.h"

using namespace std;

MatrixSorter::MatrixSorter(int **inMatrix, int inWidth, int inHeight)
{
    width = inWidth;
    height = inHeight;

    matrix = new int*[width];
    for (int i = 0; i < width; i++)
        matrix[i] = new int[height];

    for (int i =0; i < width; i++)
        for (int j = 0; j < height; j++)
            matrix[i][j] = inMatrix[i][j];
}

void MatrixSorter::sort()
{
    bool isSorted = false;
    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < width - 1; i++)
            if (matrix[i][0] > matrix[i + 1][0])
            {
                int *tempPointer = matrix[i];
                matrix[i] = matrix[i + 1];
                matrix[i + 1] = tempPointer;
                isSorted = false;
            }
    }
}

void MatrixSorter::print()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            std::cout << matrix[j][i] << " ";
        std::cout << std::endl;
    }
}

MatrixSorter::~MatrixSorter()
{
    for (int i = 0; i < width; i++)
        delete[] matrix[i];
    delete[] matrix;
}
