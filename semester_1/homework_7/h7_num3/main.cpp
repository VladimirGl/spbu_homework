#include <iostream>
#include <ctime>

#include "cuckoo.h"

using namespace std;

void testInsert() {
    cout << "testInsert\n";
    int counter = 0;
    int hashSize = 100;
    int *table1 = createTable(hashSize);
    int *table2 = createTable(hashSize);
    insert(table1, table2, hashSize, counter, 10);
    insert(table1, table2, hashSize, counter, 20);
    insert(table1, table2, hashSize, counter, 13);
    insert(table1, table2, hashSize, counter, 45);
    insert(table1, table2, hashSize, counter, 33);
    insert(table1, table2, hashSize, counter, 76);
    cout << isContains(table1, table2, hashSize, 13) << endl;
    removeValue(table1, table2, hashSize, counter, 13);
    cout << isContains(table1, table2, hashSize, 13) << endl;
    delete[] table1;
    delete[] table2;
}

void testManyRandomValue() {
    cout << "testManeRandomValues\n";
    srand(time(0));
    int counter = 0;
    int hashSize = 25;
    int *table1 = createTable(hashSize);
    int *table2 = createTable(hashSize);
    int testValue1 = 0;
    int testValue2 = 0;
    int testValue3 = 0;
    int testValue4 = 0;
    for (int i = 0; i < 27; i++) {
        int value = rand() % 250;
        if (i == 0)
            testValue1 = value;
        if (i == 25)
            testValue2 = value;
        if (i == 13)
            testValue3 = value;  
        if (i == 11)
            testValue4 = value;  
        insert(table1, table2, hashSize, counter, value);
    }
    for (int i = 0; i < hashSize; i++)
        cout << table1[i] << " ";
    cout << endl;
    for (int i = 0; i < hashSize; i++)
        cout << table2[i] << " ";
    cout << endl;
    cout << testValue1 << " ";
    cout << testValue2 << " ";
    cout << testValue3 << " ";
    cout << testValue4 << " ";
    cout << endl;
    cout << isContains(table1, table2, hashSize, testValue1) << " ";
    cout << isContains(table1, table2, hashSize, testValue2) << " ";
    cout << isContains(table1, table2, hashSize, testValue3) << " ";
    cout << isContains(table1, table2, hashSize, testValue4) << " ";
    delete[] table1;
    delete[] table2;
}

int main() {
    int i = 0;
    testInsert();
    testManyRandomValue();
    cin >> i;  
    return 0;
}
