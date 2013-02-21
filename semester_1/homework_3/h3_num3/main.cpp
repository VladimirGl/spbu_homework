#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

using namespace std;

int priority(char a) {
    if (a == '*') return 3;
    if (a == '/') return 3;
    if (a == '+') return 2;
    if (a == '-') return 2;
    if (a == '(') return 1; 
    if (a == ')') return 1;
    return 0;
}

bool isRightString(char b[]) {
    int a = 0;
    for (int i = 0; ((a >= 0) && (i <= strlen(b))); i++) {
            if (b[i] == '(')
                a++;
            if (b[i] == ')')
                a--;
    }
    return (a == 0);
}

bool isOperator(char a)
{
    if (a == '*') return true;
    if (a == '/') return true;
    if (a == '+') return true;
    if (a == '-') return true;
    return false;
}

/*
void testEmpty()
{
    cout << "testEmpty:" << endl;
    Stack *stack = createStack();
    cout << "  is empty: " << isEmpty(stack) << endl;
}

void testPush()
{
    cout << "testPush:" << endl;
    Stack *stack = createStack();
    cout << "  is empty before push: " << isEmpty(stack) << endl;
    push(stack, '5');
    cout << "  is empty after push: " << isEmpty(stack) << endl;
}

void testTop()
{
    cout << "testTop:" << endl;
    Stack *stack = createStack();
    push(stack, '5');	
    int value = top(stack);
    cout << "  top: " << value << endl;
}

void testPop()
{
    cout << "testTop:" << endl;
    Stack *stack = createStack();
    push(stack, '5');	
    int value = pop(stack);
    cout << "  pop: " << value << endl;
    cout << "  is empty before pop: " << isEmpty(stack) << endl;
}

void testDestr()
{
    cout << "testDestroy:" << endl;
    Stack *stack = createStack();
    cout << isEmpty(stack) << endl;
    push(stack, '5');
    push(stack, '7');
    push(stack, '4');
    cout << isEmpty(stack) << endl;
    destroy(stack);
    cout << isEmpty(stack);
}
*/

int main()
{
    cout << "This program converts the infix expression to postfix" << endl;
    cout << "Enter an expression without spaces, you can use: '+', '-', '*', '/', '(', ')' " << endl << endl;
    char inStr[255] = {};
    char outStr[255] = {};
    Stack *stack = createStack();
    cin.getline(inStr, 255);
    int len = strlen(inStr);
    int counter = 0;
    if (!isRightString(inStr)) {
        cout << "Bad string";
        cin >> inStr[0];
        return 1;
    }
    for (int i = 0; i < len; i++) {
        if (inStr[i] == '(') {
            push(stack, inStr[i]);
        } else {
            if (isOperator(inStr[i])) {
                while ((!isEmpty(stack)) && (priority(top(stack)) > priority(inStr[i]))) {
                    counter++;
                    outStr[counter] = pop(stack);
                }
                push(stack, inStr[i]);
            } else {
                if (inStr[i] == ')') {
                    while ((!isEmpty(stack)) && (top(stack)) != '(') {
                        counter++;
                        outStr[counter] = pop(stack);
                    }
                    pop(stack);
                } else {
                    counter++;
                    outStr[counter] = inStr[i];
                }
            }
        }
    }
    cout << endl;
    while (!isEmpty(stack)) {
        counter++;
        outStr[counter] = pop(stack);
    }
    for (int i = 1; i <= counter; i++) {
            cout << outStr[i] << " ";
    }
    cout << endl << endl;
        
/*    
    testEmpty();
    testPush();
    testTop();
    testPop();
    testDestr();
*/
    cout << "To exit the program enter the character " << endl;
    cin >> inStr[0];
    destroy(stack);
    delete stack;
    return 0;
}
