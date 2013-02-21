#include <iostream>
#include <fstream>

using namespace std;

bool isEnd(char c) {
    return (c == 0);
}

bool isOpenComment(char a, char b) {
     return ((a == '/') && (b == '*'));
}

bool isCloseComment(char a, char b) {
     return ((a == '*') && (b == '/'));
}

bool isQuote(char a) {
     return (a == '"');
}

bool isLineComment(char a, char b) {
     return ((a == '/') && (b == '/'));
}

int main()
{
    cout << "This program print all single-line comments C++\n(type //comments) from the input file" << endl << endl;
    cout << "#x, x - line nubmer" << endl;
    ifstream text("input.txt");
    if (!text)
    {
        cerr << "Error reading a file" << endl;
        getchar();
        return 1;
    } 
    char str[255];
    int i = 0;
    int num = 0;
    bool notLongComment = true;
    bool notQuote = true;
    while (!text.eof()) {
        text.getline(str, 255);
        num++;
        i = 0;
        while (!isEnd(str[i])) {
            if (isOpenComment(str[i], str[i+1]) && notLongComment && notQuote) {
                notLongComment = false;
            }
            if (isCloseComment(str[i], str[i+1]) && notQuote) {
                notLongComment = true;
            }
            if (isQuote(str[i]) && notLongComment) {
                if (notQuote) {
                    notQuote = false;
                } else {
                    notQuote = true;
                }
            }
            if (isLineComment(str[i], str[i+1]) && notLongComment && notQuote) {
                cout << "#" << num << "   ";
                while (!isEnd(str[i])) {
                cout << str[i];
                i++;
                }
                cout << endl;
            }
            if (!isEnd(str[i])) i++;
        }
    }
    text.close();
    cout << endl << "To exit the program enter the character ";
    cin >> str[0];    
    return 0;
}
