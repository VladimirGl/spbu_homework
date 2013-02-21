#include <iostream>
#include <string.h>
#include "hashString.h"

using namespace std;

const int maxLen = 255;

int main()
{
    char str[maxLen];
    char pattern[maxLen];

    cout << "This program search pattern in the string\n\n"
            "Rabin-Karp algorithm\n\n"
            "Enter the string:\n";
            
    cin.getline(str, maxLen);
    cout << "Enter the pattern:\n";
    cin.getline(pattern, maxLen);
    
    int num = search(str, pattern);

    if (num >= 0)
        cout << "Match from the " << (num + 1) << " character\n\n";
    else
        cout << "There is no such pattern\n\n";
    cout << "To exit the program enter the character ";
    cin >> str[0];
    return 0;
}
