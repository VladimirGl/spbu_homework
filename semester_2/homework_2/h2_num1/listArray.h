#pragma once

#include "list.h"

class ArrayList: public List
{
public:
    ArrayList();
    void addValueInPos(int value, int position);
    void removeValue(int value);
    bool isContained(int value) const;
    bool isEmpty() const;
    int length() const;
    void print() const;
    ~ArrayList();
protected:
    int arraySize;
    int arrayCounter;
    int **arrayList;
    int findHole();
    void increaseArray();
};
