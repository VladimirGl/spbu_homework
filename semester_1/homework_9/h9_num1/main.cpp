#include <cstdlib>
#include <iostream>
#include <string.h>
#include <fstream>

#include "hash.h"

using namespace std;

int main()
{
    cout << "This program search for equal strings and writes to the file.\n\n";
    ifstream text1("input1.txt");
    if (!text1) {
        cerr << "Error reading a file" << endl;
        getchar();
        return 1;
    }
    while (!text1.eof()) {
        string str = "";
        getline(text1, str);
        addToTable(str);
    }
    
    ifstream text2("input2.txt");
    ofstream output("output.txt");
    if (!text2) {
        cerr << "Error reading a file" << endl;
        getchar();
        return 2;
    }
    int counter = 0;
    while (!text2.eof()) {
        string str = "";
        getline(text2, str);
        if (isGeneralString(str)) {
            output << str << endl;
            counter++;
        }
    }
    
    if (counter)
        cout << counter << " matches, see results in 'output.txt'.\n\n";
    else
        cout << "No matches.\n\n";
    
    cout << "To exit the program enter the character ";
    getchar();
    
    text1.close();
    text2.close();
    output.close();        
    
    return 0;
}
