#include <fstream>
#include <iostream>

#include "base.h"

using namespace std;

void addTable(string *nameBase, int *phoneBase, int &counter) {
    ifstream base("base.txt");
    if (!base) {
        cout << "No base! Add records in the base.\n";
        return;
    }
    while (!base.eof()) {
        base >> nameBase[counter];
        base >> phoneBase[counter];
        counter++;
    }
    counter--;
    base.close();
}

void sortTable(string *nameBase, int *phoneBase, int first, int last)
{   
    string middle = nameBase[first + (last - first)/ 2];
    int newFirst = first;
    int newLast = last;
    while (newFirst <= newLast) {
        while (nameBase[newFirst] < middle) 
            newFirst++;
        while (nameBase[newLast] > middle) 
            newLast--;
        if (newFirst <= newLast) {
            swap(nameBase[newFirst], nameBase[newLast]);
            swap(phoneBase[newFirst], phoneBase[newLast]);
            newFirst++;
            newLast--;
        }
    }
    if (newFirst < last)
        sortTable(nameBase, phoneBase, newFirst, last);
    if (first < newLast)
        sortTable(nameBase, phoneBase, first, newLast);
}

void searchByName(string *nameBase, int *phoneBase, int counter) {
    cout << "Enter the name to search:\n";
    string name;
    cin >> name;
    for (int i = 0; i < counter; i++)
        if (name == nameBase[i]) {
            cout << nameBase[i] << " - " << phoneBase[i] << endl;
            return;
        }
    cout << "Name not found.\n";
    return;
}

void searchByPhone(string *nameBase, int *phoneBase, int counter) {
    cout << "Enter the phone to search:\n";
    int phone = 0;
    cin >> phone;
    for (int i = 0; i < counter; i++)
        if (phone == phoneBase[i]) {
            cout << nameBase[i] << " - " << phoneBase[i] << endl;
            return;
        }
    cout << "Phone not found.\n";
    return;    
}

void addPeopleTable(string *nameBase, int *phoneBase, int &counter) {
    cout << "Enter the name to add:\n";
    string name;
    cin >> name;
    cout << "Enter the phone to add:\n";
    int phone = 0;
    cin >> phone;
    nameBase[counter] = name;
    phoneBase[counter] = phone;
    counter++;
}

void addTextBase(string *nameBase, int *phoneBase, int counter) {
    sortTable(nameBase, phoneBase, 0, counter - 1);
    ofstream base("base.txt");
    for (int i = 0; i < counter; i++) {
        int length = nameBase[i].length();
        length = 28 - length;
        base << "  " << nameBase[i];
        for (int j = 0; j < length; j++)
            base << " ";
        base << phoneBase[i];
        base << endl;
    }
    base.close();
}
    
        
