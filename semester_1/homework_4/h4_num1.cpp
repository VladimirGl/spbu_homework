#include <iostream>

using namespace std;
         

int main()
{
    cout << "This program will define, whether it is possible, rearranging" << endl; 
    cout << "symbols in the first line, to receive the second line" << endl;
    int value[256] = {};
    char ch = '0';
    cout << "Enter the first line" << endl;
    while (ch != '\n')
    {
        ch = cin.get();
        value[ch]++;
    }
    ch = '0';
    cout << "Enter the second line" << endl;
    while (ch != '\n')
    {
        ch = cin.get();
        value[ch]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (value[i] != 0)
        {
            cout << "No" << endl;
            cin >> ch;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cin >> ch;
    return 0;
}
