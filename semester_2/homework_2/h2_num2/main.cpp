#include <iostream>

#include "arrayStack.h"
#include "stringParser.h"

using namespace std;

void testArrayStack() {
    cout << "testArrayStack\n";
    Stack *object = new ArrayStack;
    for (int i = 0; i < 75; i++) {
       object->push(i);
    }
    for (int i = 0; i < 75; i++) {
        cout << object->top() << " ";
        object->pop();
    }
    delete object;
}

void testParser() {
    cout << "testParser\n";
    char string[255];
    cin >> string;
    Parser *object = new Parser(string);
    cout << object->isCorrectExpression();
    delete object;
}


int main() {
  //  testArrayStack();
  testParser();
    cin.get();
    int i = 0;
    cin >> i;
    return 0;
}
