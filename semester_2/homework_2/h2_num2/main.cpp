#include <iostream>
#include <float.h>

#include "stackCalculate.h"

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

void testCalculate() {
    char string[255];
    cin >> string;
    PostfixCalculator *object = new PostfixCalculator(array, string);
    cout << object->calculate();
    delete object;
}
/*
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
*/
int main() {
    cout << "asd" << (int)'\0' << endl;
    testArrayStack();
    testCalculate();
//    testParser();
    int i = 0;
    cin >> i;
    return 0;
}
