#include <iostream>
#include "spiralprinter.h"

SpiralPrinter::SpiralPrinter(int **matrix, int size)
{
    matrixSize = size;
    inMatrix = new int*[matrixSize + 1];
    for (int i = 0; i <= matrixSize; i++)
        inMatrix[i] = new int[matrixSize + 1];
    for (int i = 0; i <= matrixSize; i++)
        for (int j = 0; j <= matrixSize; j++)
            inMatrix[i][j] = 0;
    for (int i = 1; i <= matrixSize; i++)
        for (int j = 1; j <= matrixSize; j++)
            inMatrix[i][j] = matrix[i][j];
    arraySize = matrixSize * matrixSize;
    spiralArray = new int[arraySize];
    for (int i = 0; i < arraySize; i++)
        spiralArray[i] = 0;
    doSpiral();
}

SpiralPrinter::~SpiralPrinter()
{
    for (int i = 0; i <= matrixSize; i++)
        delete[] inMatrix[i];
    delete[] inMatrix;
    delete[] spiralArray;
}

void SpiralPrinter::doSpiral()
{
    int x1 = int(matrixSize / 2) + 1;
    int x2 = int(matrixSize / 2) + 1;
    int counter = 0;
    spiralArray[counter] = inMatrix[x1][x2];
    counter++;
    matrixSize;
    for (int i = 1; i <= matrixSize; i++) {
        if ((i % 2) != 0) {
            for (int j = 1; j <= i && !(x1 == matrixSize && x2 == matrixSize); j++) {
                x2++;
                spiralArray[counter] = inMatrix[x1][x2];
                counter++;
            }
            for (int j = 1; j <= i && !(x1 == matrixSize && x2 == matrixSize); j++) {
                x1--;
                spiralArray[counter] = inMatrix[x1][x2];
                counter++;
            }
        }
        if ((i % 2) == 0) {
            for (int j = 1; j <= i  && !(x1 == matrixSize && x2 == matrixSize); j++) {
                x2--;
                spiralArray[counter] = inMatrix[x1][x2];
                counter++;
            }
            for (int j = 1; j <= i && !(x1 == matrixSize && x2 == matrixSize); j++) {
                x1++;
                spiralArray[counter] = inMatrix[x1][x2];
                counter++;
            }
        }
    }
}
