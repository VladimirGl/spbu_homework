#include "polynommm.h"
#include <iostream>

using namespace std;


Polynomial *createPolynomial() {
    Polynomial *pnm = new Polynomial;
    pnm->first = NULL;
    return pnm;
}

Member *createMember(int value, int degree) {
    Member *temp = new Member;
    temp->next = NULL;
    temp->value = value;
    temp->degree = degree;
    return temp;
}

double power(double x, int degree) {
    if (x == 0) {
        return 0;
    }
    double pow = 1;
    while (degree) {
        if (degree & 1)
            pow *= x;
        x *= x;
        degree >>= 1;
    }
    return pow;
}


void addSortedPolynomial(Member *&root,  int value, int degree) {
    if (root == NULL) {
        Member *temp = createMember(value, degree);
        root = temp;
        return;
    }
    if (degree > root->degree) {
        Member *temp = createMember(value, degree);
        temp->next = root;
        root = temp;
        return;
    }
    if (root->next == NULL) {
        Member *temp = createMember(value, degree);
        root->next = temp;
        return;
    }
    addSortedPolynomial(root->next, value, degree);          
}

void addSortedPolynomial(Polynomial *pnm, int value, int degree) {
    addSortedPolynomial(pnm->first, value,  degree);
}


bool isEqual(Member *root1, Member *root2) {
    while ((root1 != NULL) && (root2 != NULL)) {
        if ((root1->degree != root2->degree) || (root1->value != root2->value)) return false;
        root1 = root1->next;
        root2 = root2->next;
    }
    return true;
}

bool isEqual(Polynomial *pnm1, Polynomial *pnm2) {
    return isEqual(pnm1->first, pnm2->first);
}


double valuePolynomialX(Member *root, double x) {
    double pnmValue = 0;
    while (root != NULL) {
        pnmValue += power(x, root->degree)*root->value;
        root = root->next;
    }
    return pnmValue;
}

double valuePolynomialX(Polynomial *pnm, double x) {
    return valuePolynomialX(pnm->first, x);
}

Member *sumMember(Member *&root1, Member *&root2) {
    Member *temp = createMember(0, 0);
    temp->next = NULL;
    if (root1 == NULL) {
        temp->value = root2->value;
        temp->degree = root2->degree;
        root2 = root2->next;
        return temp;
    }
    if (root2 == NULL) {
        temp->value = root1->value;
        temp->degree = root1->degree;
        root1 = root1->next;
        return temp;
    }
    if (root1->degree > root2->degree) {
        temp->value = root1->value;
        temp->degree = root1->degree;
        root1 = root1->next;
        return temp;
    } else {
        if (root1-> degree < root2-> degree) {
            temp->value = root2->value;
            temp->degree = root2->degree;
            root2 = root2->next;
            return temp;
        } else {
            temp->value = root1->value + root2->value;
            temp->degree = root1->degree;
            root1 = root1->next;
            root2 = root2->next;
            return temp;
        }
    }
}
            

void sumPolynomial(Member *root1, Member *root2, Member *&root3) {
    if ((root1 != NULL) || (root2 != NULL)) {
        root3 = sumMember(root1, root2);
        sumPolynomial(root1, root2, root3->next);
    }
}
            
void sumPolynomial(Polynomial *pnm1, Polynomial *pnm2, Polynomial *pnm3) {
     sumPolynomial(pnm1->first, pnm2->first, pnm3->first);
}        

void removePolynomial(Member *&root) {
    if (root != NULL) {
        removePolynomial(root->next);
        delete root;
        root = NULL;
    }
}

void removePolynomial(Polynomial *pnm) {
    removePolynomial(pnm->first);
    delete pnm;
}

void printPolynomial(Member *root) {
    if (root->degree != 0) 
        cout << root->value << "x^" << root->degree;
    else
        cout << root->value;
    root = root->next;
    while (root != NULL) {
        if (root->value > 0) cout << "+" << root->value;
        else if (root->value < 0) cout << root->value;
        if (root->degree != 0) {
            if (root->degree == 1)
                cout << "x";
            else
                cout << "x^" << root->degree;
        }
        root = root->next;
    }
    cout << endl;
}

void printPolynomial(Polynomial *pnm) {
    printPolynomial(pnm->first);
}

