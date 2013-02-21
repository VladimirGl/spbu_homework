#include <iostream>
#include <fstream>

using namespace std;

void allFalse(bool b[]) {
     for (int i = 0; i <= 25; i++) {
         b[i] = false;
     }
}

bool isEnd(char c) {
     if (c == 0) return true;
     return false;
}

int main()
{
    cout << "This program removes duplicate letters in all the words of text" << endl << endl;
    cout << "Words:" << endl;
    ifstream text("input.txt");
    if (!text) {
        cerr << "Error reading a file" << endl;
        return 1;
    } 
    char str[255];
    bool b[25];
    allFalse(b);
    int i = 0;
    int num = 0;
    while (!text.eof()) {
        text.getline(str, 255);
        i = 0;
        while (!isEnd(str[i])) {
            while ((str[i] != ' ') && !isEnd(str[i])){
                num = (int)str[i] - 97;
                if (!b[num]){
                    cout << str[i];
                    b[num] = true;
                }
                i++;
            }
            allFalse(b);
            if (!isEnd(str[i])) i++;
            cout << endl;
        }
    }
    text.close();
    cout << endl << "To exit the program enter the character ";
    cin >> str[0];    
    return 0;
}
