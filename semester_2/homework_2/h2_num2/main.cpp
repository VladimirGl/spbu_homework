#include <iostream>

#include "arrayStack.h"
#include "stringParser.h"
#include "translateIntoPolish.h"

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
    object->push(22);
    object->pop();
    cout << endl;
    delete object;
}

void testParser() {
    cout << "testParser and translator\n";
    char string[255];
    cin >> string;
    Parser *objectq = new Parser(string);
    if (objectq->isCorrectExpression()) {
        TranslateIntoPolish *oneMoreObject = new TranslateIntoPolish(array, string);
        char *out = oneMoreObject->translator();
        cout << out;
        delete oneMoreObject;
    } else {
        cout << "bad expression\n";
    }
    delete objectq;
}


int main() {
    testArrayStack();
    testParser();
    int i = 0;
    cin >> i;
    return 0;
}
