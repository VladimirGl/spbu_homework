#ifndef CONSOLEPRINT_H
#define CONSOLEPRINT_H

#include "spiralprinter.h"

/**
 * @file consoleprint.h
 *
 * @section DESCRIPTION
 *
 * Realization of class, that print by spiral in the console.
 */

///ConsolePrint class
class ConsolePrint : public SpiralPrinter
{
public:
    ///Calling the base class constructor.
    ConsolePrint(int **matrix, int size):
        SpiralPrinter(matrix, size)
    {}
    void print() const;
};

#endif // CONSOLEPRINT_H
