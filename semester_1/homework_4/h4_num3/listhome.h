#ifndef _LIST_H_
#define _LIST_H_

struct List {
    int value;
    List *next;
};

List *createList(List *head);
bool isEmpty(List *head);
List *addValueList(List *temp, int value);
List *delValueList(List *temp, int value);
void printList(List *temp);
void removeList(List *temp);

#endif
