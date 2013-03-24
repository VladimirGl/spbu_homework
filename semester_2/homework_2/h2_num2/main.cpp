#include <iostream>
#include <float.h>

#include "stackCalculate.h"
#include "testStack.h"
#include "testCalculate.h"

using namespace std;

int main() {
    /*
    TestStack test1;
    QTest::qExec(&test1);

    TestCalculate test2;
    QTest::qExec(&test2);
    */

    cout << "This is the stack-calculator program\n\n"
            "You should choose type of stack (array or pointer)\n"
            "Enter 1 to choose array stack, enter 2 to choose pointer stack\n";
    int type;
    cin >> type;
    if (type != 1 && type != 2) {
        cout << "Bad type!\n\n";
        return 1;
    }
    cout << "\nEnter the expression\n"
            "You can use '+','-','*','/', brackets and integer numbers:\n"
            "Don't use spaces\n";
    char string[255] = {};
    cin >> string;
    PostfixCalculator *object = new PostfixCalculator((StackType)type, string);
    double result = object->calculate();
    delete object;
    if (result == DBL_MAX)
        cout << "Bad expression!\n\n";
    else
        cout << "\nThe result is " << result << endl << endl;
    cout << "To exit the program enter the character ";
    int i = 0;
    cin >> i;
    return 0;
}
