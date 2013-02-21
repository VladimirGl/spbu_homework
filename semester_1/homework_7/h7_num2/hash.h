#pragma once

const int hashSize = 1000;
const int base = 13;
const int wordLength = 15;

struct List
{
	char word[wordLength];
	int number;
	List *next;
}; 

List *create(char word[]);
bool isEqual(char word1[], char word2[]);
int hash(char word[]);
void addWord(List *&inTable, char word[]);
void addToTable(char word[]);
void output();
