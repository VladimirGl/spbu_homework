#ifndef _CUCKOOHASH_H_
#define _CUCKOOHASH_H_

unsigned long long const maxLoop = 1000000000;
unsigned long long const bigPrime = 739; //любое простое число, большее редпологаемого кол-ва элементов.
const double alpha = 2;
int const a1 = 157; //a1, b1, a2, b2 - любое число, меньшее bigPrime (с простыми меньше коллизий, ИМХО)
int const b1 = 131;
int const a2 = 97;
int const b2 = 293;

void insert(int *&table1, int *&table2, int &hashSize, int &counter, int value);
bool isContains(int *table1, int *table2, int hashSize, int value);
void removeValue(int *table1, int *table2, int hashSize, int &counter, int value);
int *createTable(int hashSize);
int h2 (int value, int hashSize);

#endif
