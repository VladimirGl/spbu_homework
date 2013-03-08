#ifndef SPIRALPRINTER_H
#define SPIRALPRINTER_H

class SpiralPrinter
{
public:
    SpiralPrinter(int **matrix, int size);
    virtual void print() const = 0;
    virtual ~SpiralPrinter();
protected:
    int **inMatrix;
    int *spiralArray;
    int matrixSize;
private:
    void doSpiral();
};

#endif // SPIRALPRINTER_H
