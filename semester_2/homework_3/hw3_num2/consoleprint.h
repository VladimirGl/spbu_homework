#ifndef CONSOLEPRINT_H
#define CONSOLEPRINT_H

#include "spiralprinter.h"

class ConsolePrint : public SpiralPrinter
{
public:
    ConsolePrint(int **matrix, int size):
        SpiralPrinter(matrix, size)
    {}
    void print() const;
};

#endif // CONSOLEPRINT_H
