#include <iostream>

#include "consoleprint.h"

void ConsolePrint::print() const
{
    for (int i = 0; i < (arraySize); i++)
        std::cout << spiralArray[i] << " ";
}
