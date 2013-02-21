#include "listhome.h"
#include <stdio.h>
#include <iostream>

using namespace std;

List *createList(List *head) {
    head = new List;
    head->next = NULL;
    return head;
}

bool isEmpty(List *head) {
    return (head == NULL);
}

List *addValueList(List *temp, int value) {
    List *head = temp;
    List *temp2 = new List;
    temp2->value = value;
    if (isEmpty(head))
    {
        temp2->next = NULL;
        return temp2;
    }
    if (value > temp->value) {
        temp2->next = temp;
        return temp2;
    }
    while ((temp->next != NULL) && (temp->next->value > value)) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        temp->next = temp2;
        temp2->next = NULL;
        return head;
    }
    temp2->next = temp->next;
    temp->next = temp2;
    return head;
}
    
List *delValueList(List *temp, int value) {
    List *head = temp;
    if (isEmpty(head)) {
        cout << "List is empty\n";
        return temp;
    }
    if (temp->value == value) {
        temp = temp->next;
        return temp;
    }
    while ((temp->next->value != value) && (temp->next->next != NULL)) {
        temp = temp->next;
    }
    cout << endl;
    if ((temp->next == NULL) || (temp->next->value != value)) {
        cout << "No such element\n";
        return head;
    }
    List *temp2 = temp->next;
    temp->next = temp2->next;
    return head;
}
     
void printList(List *temp) {
    if (isEmpty(temp)) {
        cout << "List is empty\n";
    }
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "\n";
}      

void removeList(List *temp)
{
    if (temp != NULL)
    {
        removeList(temp->next);
        delete temp;
    }
}
                 
        
         
