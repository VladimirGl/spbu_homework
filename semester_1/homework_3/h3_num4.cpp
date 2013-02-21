#include <cstdlib>
#include <iostream>

using namespace std;

int numOfDigits(int value) {
    int counter = 0;
    if ((value == 1) || (value == -1))
        return 0;
    while (value != 0) {
        value /= 10;
        counter++;
    }
    return counter;
}

void printSpace(int counter) {
    for (int i = 0; i < counter; i++)
        cout << " ";
}

void printSigned(int value) {
    if (value > 0) {
        cout << "+" << value;
        return;
    }
    if (value < 0) {
        cout << value;
        return;
    }
    return;
}

void printFirstString(int *factors, int maxDegree) {
    int counter = 0;
    int temp = maxDegree;
    while ((factors[counter] == 0) && (temp >= 0)) {
        temp--;
        counter++;
    }
    temp--;
    int digits = numOfDigits(factors[counter]);
    printSpace(digits);
    if (factors[counter] < 0)
        cout << " ";
    cout << " "; //x^
    cout << temp;
    temp--;
    counter++;
    for (int i = counter; i < (maxDegree - 2); i++) {
        if (factors[i] != 0) {
            digits = numOfDigits(factors[i]);
            printSpace(digits);
            cout << "  "; // +x^
            cout << temp;
        }
        temp--;
    }
}

void printSecondString(int *factors, int maxDegree) {
    int counter = 0;
    int temp = maxDegree;
    while ((factors[counter] == 0) && (temp >= 0)) {
          temp--;
          counter++;
    }
    temp--;
    int digits = numOfDigits(temp);
    if (factors[counter] == 1) 
        cout << "x";
    else if (factors[counter] == -1)
            cout << "-x";
            else
                cout << factors[counter] << "x"; 
    printSpace(digits);
    counter++;
    temp--;
    for (int i = counter; i < (maxDegree - 2); i++) {
        digits = numOfDigits(temp);
        if (factors[i] != 0) {
            if (factors[i] == 1) 
                cout << "+x";
            else if (factors[i] == -1)
                    cout << "-x";
                    else {
                        printSigned(factors[i]);
                        cout << "x";
                    }
        printSpace(numOfDigits(temp));
        }
        temp--;
    }
    if (factors[maxDegree - 2] != 0) {
        if (factors[maxDegree - 2] != 0) {
            if (factors[maxDegree - 2] == 1) 
                cout << "+x";
            else if (factors[maxDegree - 2] == -1)
                    cout << "-x";
                    else {
                        printSigned(factors[maxDegree - 2]);
                        cout << "x";
                    }
        }
    }
    if (factors[maxDegree - 1] != 0)
        printSigned(factors[maxDegree - 1]);
}

int main()
{
    cout << "This program print the polynomial in 'beautiful' form\n\n"
            "Enter the max degree of polynomial ";
    int maxDegree = 0;
    cin >> maxDegree;
    maxDegree++;
    int *factors = new int[maxDegree];
    
    cout << "Enter the factors\n";
    for (int i = 0; i < maxDegree; i++)
        cin >> factors[i];

    cout << "Polynomial:\n\n";
    printFirstString(factors, maxDegree);
    cout << endl;
    printSecondString(factors, maxDegree);
    
    cout << "\n\nTo exit the program enter the character ";
    cin.get();
    cin.get();
    delete[] factors;
    
    return 0;
}
