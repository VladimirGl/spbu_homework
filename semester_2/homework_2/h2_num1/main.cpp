#include <iostream>

#include "listArray.h"

using namespace std;

void testAdd() {
    cout << "test Add\n";
    List *object = new ArrayList;
    for (int i = 1; i <= 70; i++) {
        object->addValueInPos(i, (71 - i));
    }
    object->print();
    cout << endl;
    delete object;
}

void testRemove() {
    cout << "testRemove\n";
    List *object = new ArrayList;
    for (int i = 1; i <= 70; i++)
        object->addValueInPos(i, (71 - i));
    cout << "remove even:\n";
    for (int i = 2; i <= 70; i += 2)
        object->removeValue(71 - i);
    object->print();
    cout << "add to end:\n";
    for (int i = 1; i < 20; i++)
        object->addValueInPos((i + 70), 75);
    object->print();
    cout << "remove odd:\n";
    for (int i = 3; i <= 90; i += 2)
        object->removeValue(91 - i);
    object->print();
    delete object;
}

int main() {
    testAdd();
    testRemove();
    cin.get();
    cin.get();    
    return 0;
 }
