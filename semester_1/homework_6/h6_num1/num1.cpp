#include <cstdlib>
#include <iostream>
#include "bst.h"

using namespace std;

enum Command {
    ext = 0,
    add = 1,
    del = 2,
    srh = 3,
    prtDown = 4,
    prtUp = 5,
};

bool isCommand(int i) {
    return (i == ext) || (i == add) || (i == del) || (i == srh) ||(i == prtDown) ||(i == prtUp);
    }  

void programFace() {
    Tree *tree = createTree();
    int command = 0;
    while (1) {
        cout << "Enter the command - ";
        cin >> command;
        if (!isCommand(command)) {
            cout << "Bad command! Try to enter another command\n";
        }
        switch (command) {
            case ext: {
                cout << "\nGoodbye!";
                removeTree(tree);
                delete tree;
                return;
            }
            case add: {
                cout << "Enter the new element - ";
                int addValue = 0;
                cin >> addValue;
                if (!exists(tree, addValue)) {
                    addElement(tree, addValue);
                } else {
                    cout << "Already have an element" << endl;
                }
                break;
            }
            case del: {
                cout << "Enter the element to delete - ";
                int delValue = 0;
                cin >> delValue;
                deleteElement(tree, delValue);
                break;
            }
            case srh: {
                cout << "Enter the element to search - ";
                int srhValue = 0;
                cin >> srhValue;
                if (exists(tree, srhValue)) {
                    cout << "Element found" << endl;
                } else {
                    cout << "Element not found" << endl << endl;
                    cout << "If you want to add this element\nenter the 'y', else enter the 'n'  ";
                    char addCmd;
                    cin >> addCmd;
                    cout << endl;
                    if (addCmd == 'y') addElement(tree, srhValue);
                }
                break;
            }
            case prtDown: {
                if (tree->root != NULL) {
                    inorderRight(tree);
                } else {
                    cout << "Set is empty";
                }
                cout << endl;
                break;
            }
            case prtUp: {
                if (tree->root != NULL) {
                    inorderLeft(tree);
                } else {
                    cout << "Set is empty";
                }
                cout << endl;
                break;    
            }
        }     
    }           
}

int main()
{
    cout << "This program implements ADT 'set' based on a binary search tree" << endl;
    cout << "You can use this commands:\n0 - exit the program\n1 - add a new element to the set\n2 - remove an element from the set\n";
    cout << "3 - find an element in the set\n4 - print set in descending order\n5 - print set in ascending order\n\n";
    programFace();
    return 0;
}
