#include <iostream>

#include "listArray.h"
#include "listPointer.h"

using namespace std;

void testAddArray() {
    cout << "test AddArrayList\n";
    List *object = new ArrayList;
    for (int i = 1; i <= 70; i++) {
        object->addValueInPos(i, (71 - i));
    }
    object->print();
    cout << endl;
    delete object;
}

void testRemoveArray() {
    cout << "\ntestRemoveArrayList\n";
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

void testAddPointer() {
    cout << "\n\ntest AddPointerList\n";
    List *object = new PointerList;
    for (int i = 1; i <= 70; i++) {
        object->addValueInPos(i, (71 - i));
    }
    object->print();
    cout << endl;
    delete object;
}

void testRemovePointer() {
    cout << "\ntestRemovePointerList\n";
    List *object = new PointerList;
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
    testAddArray();
    testRemoveArray();
    testAddPointer();
    testRemovePointer();
    List* object = new PointerList;
    cin.get();
    cin.get();    
    return 0;
 }
