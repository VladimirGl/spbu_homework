#include <cstdlib>
#include <iostream>
#include <fstream>

#include "base.h"

using namespace std;

enum Command {
    ext = 0,
    add = 1,
    srhN = 2,
    srhP = 3,
    save = 4,
};

bool isCommand(int command) {
    return (command >= 0 && command <= 4);
}

void programFace() {
    cout << "     Telephone book!\nYou can use this commands:\n"
            " 0 - exit\n 1 - add record (name and phone)\n"
            " 2 - seach by name\n 3 - search by phone\n"
            " 4 - save base in the .txt file\n\n";
}

void programWork() {
    string *nameBase = new string[100];
    int phoneBase[100];
    int counter = 0;
    programFace();
    addTable(nameBase, phoneBase, counter);
    while (1) {
        cout << "command: ";
        int command = 0;
        cin >> command;
        if (!isCommand(command))
            cout << "Bad command. Enter enother command\n";
        switch (command) {
            case ext: {                     
                cout << "Goodbye!";  
                delete[] nameBase;
                return;
            } 
            case add: {
                addPeopleTable(nameBase, phoneBase, counter);
                cout << "Record added.\n";
                break;
            }
            case srhN: {
                searchByName(nameBase, phoneBase, counter);
                break;
            }
            case srhP: {
                searchByPhone(nameBase, phoneBase, counter);
                break;
            }
            case save: {
                addTextBase(nameBase, phoneBase, counter);
                cout << "Base saved.\n";
                break;
            }
        }
    }
    delete[] nameBase;
}

int main()
{
    programWork();
    return 0;
}
