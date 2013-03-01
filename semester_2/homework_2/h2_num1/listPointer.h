#pragma once 

#include "list.h"

struct ListElement {
    int value;
    ListElement *next;
};

class PointerList: public List {
public:
    PointerList();
    void addValueInPos(int value, int position);
    void removeValue(int value);
    bool isContained(int value) const;
    bool isEmpty() const;
    int length() const;
    void print() const;
    ~PointerList();
protected:
    ListElement *list;
    int memberCounter;
};
