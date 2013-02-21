#include <iostream>

#include "analyzer.h"

using namespace std;

int main() {
    cout << "This program lexical analyzer.\nYou can use real numbers, brackets and multiply/addition operations.\n\n";
    cout << "Enter the expression:\n";
    char str[255];
    cin >> str;
    if (isCorrectExpression(str))
        cout << "\nThe expression is correct.\n\n";
    else
        cout << "\nThe expression is incorrect.\n\n";
    cout << "To exit the program enter the character ";
    cin >> str;
    return 0;
}
