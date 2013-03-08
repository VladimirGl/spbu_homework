#ifndef FILEPRINT_H
#define FILEPRINT_H

#include "spiralprinter.h"

class FilePrint : public SpiralPrinter
{
public:
    FilePrint(int **matrix, int size):
        SpiralPrinter(matrix, size)
    {}
    void print() const;
};

#endif // FILEPRINT_H
