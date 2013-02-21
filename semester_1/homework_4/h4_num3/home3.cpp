#include <stdio.h>
#include <iostream>
#include "listhome.h"

using namespace std;

enum Command {
    ext = 0,
    add = 1,
    del = 2,
    prt = 3,
};

void programFace() {
    List *head = new List;
    while (1) {
    cout << "Enter the command - ";
    int value = 0;
    cin >> value;
    if (value == ext) {
        removeList(head);
        delete head;
        return;
    }
    if ((value != add) && (value != del) && (value != prt)) {
        cout << "Bad value, try to enter another value\n";
    }
    if (value == add) {
        int num = 0;
        cout << "Enter the new value: ";
        cin >> num;
        head = addValueList(head, num);
    }
    if (value == del) {
        int num = 0;
        cout << "Enter the value to delete: ";
        cin >> num;
        head = delValueList(head, num);
    }
    if (value == prt) {
        printList(head);
    }
    }
}

int main()
{
    cout << "0 - exit\n1 - add value to sorted list\n2 - remove value from list\n3 - print list\n";
    programFace();
    return 0;
}
