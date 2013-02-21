#pragma once

struct Member {
    int value;
    int degree;
    Member *next;
};

struct Polynomial {
    Member *first;
};

Polynomial *createPolynomial();
void addSortedPolynomial(Polynomial *pnm, int value, int degree);
void printPolynomial(Polynomial *pnm);
bool isEqual(Polynomial *pnm1, Polynomial *pnm2);
double valuePolynomialX(Polynomial *pnm, double x);
void sumPolynomial(Polynomial *pnm1, Polynomial *pnm2, Polynomial *pnm3);
void removePolynomial(Polynomial *pnm);


