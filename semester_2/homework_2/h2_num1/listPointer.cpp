#include "listPointer.h"

PointerList::PointerList() {
    list = NULL;
    memberCounter = 0;
}

ListElement *createElement(int value, ListElement *pointer) {
    ListElement *temp = new ListElement;
    temp->value = value;
    temp->next = pointer;
    return temp;
}

bool PointerList::isEmpty() const {
    return (list == NULL);
}

void PointerList::addValueInPos(int value, int position) {
    if (isEmpty()) {
        list  = createElement(value, NULL);
        memberCounter++;
        return;
    }
    if (position > memberCounter)
        position = memberCounter + 1; 
    ListElement *temp = list;
    for (int i = 1; i < (position - 1); i++)
        temp = temp->next;
    ListElement *newElement = createElement(value, temp->next);
    temp->next = newElement;
    memberCounter++;
}

bool PointerList::isContained(int value) const {
    ListElement *temp = list;
    int counter = 0;
    while (counter <= memberCounter) {
        if (temp->value == value)
            return true;
        temp = temp->next;
        counter++;
    }
    return false;
}

void PointerList::removeValue(int value) {
    if (!isContained(value)) {
        cout << "List does not contain this element\n";
        return;
    }
    if (list->value == value) {
        ListElement *deletedElement = list;
        list = list->next;
        delete deletedElement;
        memberCounter--;
        return;
    }    
    ListElement *temp = list;
    while (temp->next->value != value)
        temp = temp->next;
    ListElement *deletedElement = temp->next;
    temp->next = temp->next->next;
    memberCounter--;
    delete deletedElement;
}   
    
int PointerList::length() const {
    return (memberCounter);
}

void PointerList::print() const {
    if (isEmpty()) {
        cout << "List is empty\n";
        return;
    }   
    ListElement *temp = list;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

PointerList::~PointerList() {
    ListElement *temp = list;
    while (list) {
        temp = temp->next;
        delete list;
        list = temp;
    }
    delete list;
}
    
        
        
     
