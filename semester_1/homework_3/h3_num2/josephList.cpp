#include <iostream>

#include "josephList.h"

using namespace std;

List *createJosephList(int numOfElements) {
    List *head = new List;
    List *temp = head;
    head->value = 1;
    head->next = head;
    for (int i = 2; i <= numOfElements; i++) {
        List *newElement = new List;
        newElement->value = i;
        temp->next = newElement;
        newElement->next = head;
        temp = newElement;
    }
    return head;
}

void removeByStep(List *head, int reqPosition, int numOfElements, int step, bool &flag) {
    List *temp = head;
    int removed = 0;
    int i = 1;
    while (removed < (numOfElements - 1)) {
        while (i < (step - 1)) {
            i++;
            temp = temp->next;
        }
        i = 0;
        removed++;
        List *temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
    }
    if (temp->value == reqPosition) {
        flag = false;
        cout << "Step: " << step << endl;
    }
    delete temp;
}
