#include <iostream>
#include <string.h>

#include "hash.h"


using namespace std;

List *hashTable[hashSize];

List *create(string str) {
    List *temp = new List;
    int len = str.length();
    temp->str = str;
    temp->number = 1;
    temp->next = NULL;
}

bool isEqual(string str1, string str2) {
     if (str1 == str2)
         return true;
     return false;
}

int hash(string str) {
    int counter = 0;
    int key = 0;
    int power = base;
    while ((str[counter] != '\0')) {
          key = key + (((int)str[counter] * power) % hashSize);
          power = power * base;
          counter++;
    }
    key = (key % hashSize);
    return key;
}

void addWord(List *&inTable, string str) {
     if (inTable == NULL) {
         inTable = create(str);
     } else {
         if (isEqual(str, inTable->str)) {
             inTable->number++;
         } else {
             addWord(inTable->next, str);
         }
     }
}
             
void addToTable(string str) {
    addWord(hashTable[hash(str)], str);
}

bool search(List *inTable, string str) {
     if (inTable == NULL) {
         return false;
     } else {
         if (isEqual(str, inTable->str)) {
             return true;
         } else {
             search(inTable->next, str);
         }
     }
}

bool isGeneralString(string str) {
    return search(hashTable[hash(str)], str);
}
                  

