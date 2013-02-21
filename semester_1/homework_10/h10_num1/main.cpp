#include "polynommm.h"
#include <cstdlib>
#include <iostream>


using namespace std;

enum Command {
    ext = 0,
    addFirst = 1,
    addSecond = 2,
    printFirst = 3,
    printSecond = 4,
    equals = 5,
    valueX = 6,
    sum = 7,
    help = 8,
};

bool isCommand(int command) {
    return ((command >= 0) && (command <= 9));
}

void programHelloUser() {
    cout << "This program to work with polynomials"
            "You can use this commands:\n0 - exit the program\n1 - add first polynomial\n"
            "2 - add second polynomial\n3 - print first polynomial\n4 - print second polynomial\n"
            "5 - check first and second polynomial equality\n"
            "6 - calculate the value of the polynomial at the point X\n7 - calculating the sum of polynomials\n"
            "8 - help (list of commands)\n\n";
}

void programWork() {
    Polynomial *pnm1 = createPolynomial();
    Polynomial *pnm2 = createPolynomial();
    Polynomial *pnm3 = createPolynomial();
    int command = 0;
    while (1) {
        cout << "\nEnter the command - ";
        cin >> command;
        if (!isCommand(command)) 
            cout << "Bad command! Try to enter another command\n";
        switch (command) {
            case ext: {
                cout << "\nGoodbye!";
                removePolynomial(pnm1);
                removePolynomial(pnm2);
                removePolynomial(pnm3);
                return;
            }
            case addFirst: {
                removePolynomial(pnm1);
                pnm1 = createPolynomial();
                cout << "\nEnter the first polynomial.\nEnter couples factor/degree of a space\nTo stop enter 0 0\n";
                int degree = 0;
                int value = 0;
                cin >> value >> degree;
                while ((degree != 0) || (value != 0)) {
                    addSortedPolynomial(pnm1, value, degree);
                    cin >> value >> degree;
                }
                break;
            }
            case addSecond: {
                cout << "\nEnter the second polynomial.\nEnter couples factor/degree of a space\nTo stop enter 0 0\n";
                removePolynomial(pnm2);
                pnm2 = createPolynomial();
                int degree = 0;
                int value = 0;
                cin >> value >> degree;
                while ((degree != 0) || (value != 0)) {
                    addSortedPolynomial(pnm2, value, degree);
                    cin >> value >> degree;
                }
                break;
            }
            case printFirst: {
                if (pnm1->first == NULL) {
                    cout << "Enter the first polynomial\n";
                    break;
                }
                printPolynomial(pnm1);
                break;
            }
            case printSecond: {
                 if (pnm2->first == NULL) {
                     cout << "Enter the second polynomial\n";
                     break;
                }
                printPolynomial(pnm2);
                break;
            }   
            case equals: {
                if (pnm1->first == NULL) {
                    cout << "Enter the first polynomial\n";
                    break;
                }
                if (pnm2->first == NULL) {
                    cout << "Enter the second polynomial\n";
                    break;
                }
                if (isEqual(pnm1, pnm2))
                    cout << "Polynomials are equal\n";
                else
                    cout << "Polynomials aren't equal\n";
                break;
            }
            case valueX: {
                if (pnm1->first == NULL) {
                    cout << "Enter the first polynomial\n";
                    break;
                }
                double x = 0;
                cout << "Enter the value of X - ";
                cin >> x;
                double inX = valuePolynomialX(pnm1, x);
                cout << "The value in X is " << inX << endl;
                break;
            }
            case sum: {
                if (pnm1->first == NULL) {
                    cout << "Enter the first polynomial\n";
                    break;
                }
                if (pnm2->first == NULL) {
                    cout << "Enter the second polynomial\n";
                    break;
                }
                removePolynomial(pnm3);
                Polynomial *pnm3 = createPolynomial();
                sumPolynomial(pnm1, pnm2, pnm3);
                cout << "Sum:\n";
                printPolynomial(pnm3);
                break;
            }
            case help: {
                 programHelloUser();
                 break;
            }   
        }
    } 
}         
                
                

int main()
{
//    testAdd();
//    testIsEqual();
//    testValueInX();
//    testSum();
    programHelloUser();
    programWork();
    return 0;
}


 

/*
void testAdd() {
    cout << "test Add" << endl;
    Polynomial *pnm = createPolynomial();
    addSortedPolynomial(pnm, 3, 3);
    addSortedPolynomial(pnm, 1, 1);
    addSortedPolynomial(pnm, 2, 2);
    addSortedPolynomial(pnm, 0, 0);
    addSortedPolynomial(pnm, 5, 5);
    addSortedPolynomial(pnm, 8, 8);
    addSortedPolynomial(pnm, 4, 4);
    printPolynomial(pnm);
    cout << endl;
}

void testIsEqual() {
    cout << "test isEqual" << endl;
    Polynomial *pnm1 = createPolynomial();
    Polynomial *pnm2 = createPolynomial();
    addSortedPolynomial(pnm1, 3, 3);
    addSortedPolynomial(pnm1, 1, 1);
    addSortedPolynomial(pnm1, 2, 2);
    addSortedPolynomial(pnm1, 0, 0);
    addSortedPolynomial(pnm1, 5, 5);
    addSortedPolynomial(pnm1, 8, 8);
    addSortedPolynomial(pnm1, 4, 4);
    addSortedPolynomial(pnm2, 3, 3);
    addSortedPolynomial(pnm2, 4, 4);
//    addSortedPolynomial(pnm2, 2, 2);
    addSortedPolynomial(pnm2, 0, 0);
    addSortedPolynomial(pnm2, 5, 5);
    addSortedPolynomial(pnm2, 8, 8);
    addSortedPolynomial(pnm2, 1, 1);
    cout << isEqual(pnm1, pnm2) << endl;
}

void testValueInX() {
    cout << "test ValueInX" << endl;
    Polynomial *pnm = createPolynomial();
    addSortedPolynomial(pnm, 3, 3);
    addSortedPolynomial(pnm, 1, 1);
    addSortedPolynomial(pnm, 2, 2);
    addSortedPolynomial(pnm, 5, 0);
    addSortedPolynomial(pnm, 5, 5);
    addSortedPolynomial(pnm, 8, 8);
    addSortedPolynomial(pnm, 4, 4);
    cout << valuePolynomialX(pnm, 2);
    cout << endl;
}

void testSum() {
    cout << "test Sum" << endl;
    Polynomial *pnm1 = createPolynomial();
    addSortedPolynomial(pnm1, 3, 3);
    addSortedPolynomial(pnm1, 1, 1);
    addSortedPolynomial(pnm1, 2, 2);
    addSortedPolynomial(pnm1, 5, 0);
    addSortedPolynomial(pnm1, 5, 5);
    addSortedPolynomial(pnm1, 8, 8);
    addSortedPolynomial(pnm1, 4, 4);
    printPolynomial(pnm1);
    Polynomial *pnm2 = createPolynomial();
    addSortedPolynomial(pnm2, 3, 3);
    addSortedPolynomial(pnm2, 1, 1);
    addSortedPolynomial(pnm2, 5, 0);
    addSortedPolynomial(pnm2, 5, 5);
    addSortedPolynomial(pnm2, 8, 8);
    addSortedPolynomial(pnm2, 4, 4);
    printPolynomial(pnm2);
    Polynomial *pnm3 = createPolynomial();
    sumPolynomial(pnm1, pnm2, pnm3);
    printPolynomial(pnm3);
}
*/

