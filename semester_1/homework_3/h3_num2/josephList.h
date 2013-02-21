#pragma once

struct List {
    int value;
    List *next;
};

List *createJosephList(int numOfElements);
void removeByStep(List *head, int reqPosition, int numOfElements, int step, bool &flag);

