#ifndef MATRIXSORTER_H
#define MATRIXSORTER_H

/**
 * @file matrixsorter.h
 *
 * @section DESCRIPTION
 *
 * MatrixSorter class realization.
 */

///MatrixSorter class
class MatrixSorter
{
public:
    ///Constructor, that copies the matrix in object.
    MatrixSorter(int **inMatrix, int inWidth, int inHeight);

    ///Function sort the columns of matrix of the first elemen.
    void sort();

    void print();
protected:
    int **matrix;
    int width;
    int height;
};

#endif // MATRIXSORTER_H
