#ifndef SPIRALPRINTER_H
#define SPIRALPRINTER_H

/**
 * @file spiralprinter.h
 *
 * @section DESCRIPTION
 *
 * This is a program, that print matrix at round it on a spiral.
 */

///SpiralPrinter class
class SpiralPrinter
{
public:
    ///Constructor, that copies the matrix in object.
    SpiralPrinter(int **matrix, int size);

    virtual void print() const = 0;

    ///Virtual distructor.
    virtual ~SpiralPrinter();
protected:
    int **inMatrix;
    int *spiralArray;
    int matrixSize;
    int arraySize;
private:
    ///Fill the array, contains the numbers in a spiral.
    void doSpiral();
};

#endif // SPIRALPRINTER_H
