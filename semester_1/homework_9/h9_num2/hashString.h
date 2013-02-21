#pragma once

const int base = 2;

void hash(char *str1, char *str2, int len, int &h1, int &h2);
int reHash(int old, int subt, int add, int d);
int search(char *str, char *substr);
