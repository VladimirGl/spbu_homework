#include <iostream>

#include "cuckoo.h"

using namespace std;

int h1(int value, int hashSize) {
    return (((a1 * value) + b1) % bigPrime) % hashSize;
}


int h2 (int value, int hashSize) {
    return (((a2 * value) + b2) % bigPrime) % hashSize;
}


int *createTable(int hashSize) {
    int *table = new int[hashSize];
    for (int i = 0; i < hashSize; i++)
        table[i] = -1;
    return table;
}


void rehash(int *&table1, int *&table2, int &hashSize, int &counter) {
     counter = 0;
     int newHashSize = int(hashSize * alpha);
     int *newTable1 = createTable(newHashSize);
     int *newTable2 = createTable(newHashSize);
     for (int i = 0; i < hashSize; i++) {
         if (table1[i] != -1)
             insert(newTable1, newTable2, newHashSize, counter, table1[i]);
         if (table2[i] != -1)
             insert(newTable1, newTable2, newHashSize, counter, table2[i]);
     }
     hashSize = newHashSize;
     table1 = newTable1;
     table2 = newTable2;
}


bool isContains(int *table1, int *table2, int hashSize, int value) {
    return (table1[h1(value, hashSize)] == value || table2[h2(value, hashSize)] == value);
}

void removeValue(int *table1, int *table2, int hashSize, int &counter, int value) {
    if (!isContains(table1, table2, hashSize, value))
        return;
    counter--;
    if (table1[h1(value, hashSize)] == value)
        table1[h1(value, hashSize)] = -1;
    else if (table2[h2(value, hashSize)] == value)
        table2[h2(value, hashSize)] = -1;
}

bool lookup(int *table1, int *table2, int hashSize, int value) {
    if (table1[h1(value, hashSize)] == -1) {
        table1[h1(value, hashSize)] = value;
        return true;
    } else if (table2[h2(value, hashSize)] == -1) {
            table2[h2(value, hashSize)] = value;
            return true;
        }
    return false;
}


void insert(int *&table1, int *&table2, int &hashSize, int &counter, int value) {
    if (isContains(table1, table2, hashSize, value))
        return;
    if (counter == hashSize) {
        rehash(table1, table2, hashSize, counter);
        insert(table1, table2, hashSize, counter, value);
    }
    if (lookup(table1, table2, hashSize, value)) {
        counter++;
        return;
    }
    for (int i = 0; i < maxLoop; i++) {
        swap(value, table1[h1(value, hashSize)]);
        if (value == -1) {
            counter++;
            return;
        }
        swap(value, table2[h2(value, hashSize)]);
        if (value == -1) {
            counter++;
            return;
        }
    }
    rehash(table1, table2, hashSize, counter);
    insert(table1, table2, hashSize, counter, value);
}


