#include <fstream>

#include "fileprint.h"

void FilePrint::print() const
{
    std::ofstream output("output.txt");
    for (int i = 0; i < arraySize; i++)
        output << spiralArray[i] << " ";
    output.close();
}
