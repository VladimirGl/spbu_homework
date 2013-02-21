#include "hash.h"
#include <iostream>

using namespace std;

List *hashTable[hashSize];

List *create(char word[]) {
    List *temp = new List;
    int counter = 0;
    for (int i = 0; i < wordLength; i++) {
        temp->word[i] = NULL;
    }
    while (word[counter] != '\0') {
          temp->word[counter] = word[counter];
          counter++;
    }
    temp->number = 1;
    temp->next = NULL;
}

bool isEqual(char word1[], char word2[]) {
     int counter = 0;
     while ((word1[counter] != '\0') || (word2[counter] != '\0')) {
         if (word1[counter] != word2[counter])
             return false;
         counter++;
     }
     if (word1[counter] != word2[counter]) 
         return false;
     return true;
}

int hash(char word[]) {
    int counter = 0;
    int key = 0;
    int power = base;
    while (word[counter] != '\0') {
          key = key + (((int)word[counter] * power) % hashSize);
          power = power * base;
          counter++;
    }
    key = (key % hashSize);
    return key;
}

void addWord(List *&inTable, char word[]) {
     if (inTable == NULL) {
         inTable = create(word);
     } else {
         if (isEqual(word, inTable->word)) {
             inTable->number++;
         } else {
             addWord(inTable->next, word);
         }
     }
}
             
void addToTable(char word[]) {
    addWord(hashTable[hash(word)], word);
}

void output() {
     for (int i = 0; i < hashSize; i++)
         if (hashTable[i] != NULL)
             while (hashTable[i] != NULL) {
                   cout << hashTable[i]->word << " - " << hashTable[i]->number << endl;
                   List *temp = hashTable[i];
                   hashTable[i] = temp->next;
                   delete temp;
             }
}
                  
