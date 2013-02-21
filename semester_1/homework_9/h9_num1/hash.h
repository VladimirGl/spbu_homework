#pragma once

#include <string.h>

using namespace std;

const int hashSize = 1000;
const int base = 13;
const int wordLength = 15;

struct List
{
	string str;
	int number;
	List *next;
}; 

List *create(string str);
bool isEqual(string str1, string str2);
int hash(string str);
void addToTable(string str);
bool isGeneralString(string str);
