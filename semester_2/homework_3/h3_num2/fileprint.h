#ifndef FILEPRINT_H
#define FILEPRINT_H

#include "spiralprinter.h"

/**
 * @file fileprint.h
 *
 * @section DESCRIPTION
 *
 * Realization of class, that print by spiral in the file.
 */


///FilePrint class
class FilePrint : public SpiralPrinter
{
public:
    ///Calling the base class constructor.
    FilePrint(int **matrix, int size):
        SpiralPrinter(matrix, size)
    {}
    void print() const;
};

#endif // FILEPRINT_H
