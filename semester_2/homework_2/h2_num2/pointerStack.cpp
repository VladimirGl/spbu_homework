#include <iostream>

#include "pointerStack.h"

using namespace std;

PointerStack::PointerStack() {
    stack = NULL;
}

bool PointerStack::isEmpty() const {
    return (stack == NULL);
}

void PointerStack::push(double value) {
     stack = new StackElement(stack, value);
     return;
}

double PointerStack::top() const {
    if (isEmpty()) {
        cout << "Stack is empty!";
        return INT_MAX;
    }
    return stack->value;
}

void PointerStack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty!";
    }
    StackElement *popedElement = stack;
    stack = stack->next;
    delete popedElement;
    return;
}

PointerStack::~PointerStack() {
    StackElement *temp = stack;
    while (stack) {
        temp = temp->next;
        delete stack;
        stack = temp;
    }
    delete stack;
}
     
         
