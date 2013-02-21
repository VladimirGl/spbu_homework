#include <iostream>

using namespace std;

enum Command {
    start = 0,
    sign = 1,
    intPart = 2,
    point = 3,
    frctPart = 4,
    expChar = 5,
    expSign = 6,
    exponent = 7,
    firstPoint = 8,
};

bool isNumber()
{
    int state = start;
    bool isNum = true;
    char ch = cin.get();
    while (ch != '\n') {
        if (isalpha(ch) && ((ch != 'e') && (ch != 'E')))
            isNum = false;
        if (!isNum) {
            while (ch != '\n')
                ch = cin.get();
            return false;
        }
        switch (state)
        {
            case start: {
                if (ch == '+' || ch == '-')
                    state = sign;
                else if (isdigit(ch))
                    state = intPart;
                else if (ch == '.')
                    state = firstPoint;
                else
                    isNum = false;
                break;
            }
            case sign: {
                if (isdigit(ch))
                    state = intPart;
                else if (ch == '.')
                    state = point;
                else
                    isNum = false;
                break;
            }
            case intPart: {
                if (isdigit(ch)) {
                    ch = cin.get();
                    continue;   
                } else if (ch == '.')
                    state = point;
                else if (ch == 'e' || ch == 'E')
                    state = expChar;
                else
                    isNum = false;
                break;
            }
            case point: {
                if (isdigit(ch))
                    state = frctPart;
                else if (ch == 'e' || ch == 'E')
                    state = expChar;
                else
                    isNum = false;
                break;
            }
            case frctPart: {
                if (isdigit(ch)) {
                    ch = cin.get();             
                    continue;
                }
                else if (ch == 'e' || ch == 'E')
                    state = expChar;
                else
                    isNum = false;
                break;
            }
            case expChar: {
                if (isdigit(ch))
                    state = exponent;
                else if (ch == '-' || ch == '+') {
                    ch = cin.get();
                    state = expSign;
                }
                else
                    isNum = false;
                break;
            }
            case expSign: {
                if (isdigit(ch))
                    state = exponent;
                else
                    isNum = false;
                break;
            }
            case exponent: {
                if (!isdigit(ch))
                    isNum = false;
                break;
            }
            case firstPoint: {
                if (isdigit(ch))
                    state = frctPart;
                else
                    isNum = false;
                break;
            }
        }
        ch = cin.get();
    }
    if (!(state == expChar || state == firstPoint || state == sign || state == expSign || state == start))
        return true;
    return false;
}

int main()
{
    clog << "This program checks whether a string is a real number\n\n"
            "Enter the string:\n";
    if (isNumber())
        cout << "\nString is a real number\n" << endl;
    else
        cout << "\nString is not real number\n" << endl;
    cout << "To exit the program enter the character ";
    cin.get();
    return 0;
}

