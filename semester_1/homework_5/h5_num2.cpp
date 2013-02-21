#include <stdio.h>
#include <iostream>

using namespace std;

typedef unsigned long long ullong;
const ullong bigMant = 10000000000000000000;

union doubleParsed
{
    double doubleValue;
    ullong bits;
};

ullong returnMant(doubleParsed n)
{
    ullong mask = 1;
    mask <<= 51;
    ullong toNext = 0;    
    toNext = ~toNext;      
    ullong max = toNext / 10;
    toNext >>= 12;            
    ullong mant = 0;
    ullong half = 1; 
    int i = 0;    
    while (toNext & n.bits)
    {
        if (mant <= max) 
        {
            mant = mant * 10;  
            half = half * 5;
            i++;
        }     
        else   
            half = half / 2;
        if (n.bits & mask)
            mant = mant + half;
        mask >>= 1;
        toNext >>=1;
    }
    return mant;
}

char returnSign(doubleParsed n) {
    ullong mask = 1;
    mask <<= 63;
    if (mask & n.bits) return '-';
    return '+';
}

int returnExp(doubleParsed n)
{
    n.bits <<= 1;
    n.bits >>= 53;
    int exp = (n.bits - 1023);
    return exp;
}

ullong roundMant(ullong mant) {
    const int round = 10000;
    if (mant > bigMant)                                // округляем до 16 знаков, если мантисса длинее
        mant = ullong(mant / round);
    while ((mant % 10) == 0) mant = mant / 10;         // избавляемся от нулей (если есть незначащие нули)
    return mant;
}

int main()
{
    cout << "This program prints a double number in exponential form" << endl << endl;
    cout << "Enter the number ";
    doubleParsed n;
    cin >> n.doubleValue;  
    cout << endl << "  ";
        if (!(n.bits << 1)) {
            cout << "0" << endl;
        } else {
            ullong mant = returnMant(n);
            mant = roundMant(mant);
            cout << returnSign(n);
            cout << "1." << mant;
            cout << "*2^(" << returnExp(n) << ")" << endl;;
        }
    cout << "To exit the program enter the character ";
    cin >> n.bits;
    return 0;
}

