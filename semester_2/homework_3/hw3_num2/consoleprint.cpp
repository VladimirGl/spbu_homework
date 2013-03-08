#include <iostream>

#include "consoleprint.h"

void ConsolePrint::print() const
{
    for (int i = 0; i < (matrixSize * matrixSize); i++)
        std::cout << spiralArray[i] << " ";
}
