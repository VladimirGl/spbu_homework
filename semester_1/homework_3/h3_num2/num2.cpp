#include <cstdlib>
#include <iostream>

#include "josephList.h"

using namespace std;

int main()
{
    cout << "This program displays the values of k, for which\n"
            "the latest will be i-th element of the original list\n\n";
    cout << "Enter the number of elements ";
    int numOfElements = 0;
    cin >> numOfElements;
    cout << "Enter the required position ";
    int reqPosition = 0;
    cin >> reqPosition;
    cout << endl;
    bool flag = true;
    if (reqPosition == numOfElements) {
        cout << "Step: 1\n";
        flag = false;
    }
    for (int step = 2; step <= numOfElements; step++) {
        List *counting = createJosephList(numOfElements);
        removeByStep(counting, reqPosition, numOfElements, step, flag);
    }
    if (flag)
        cout << "No such steps\n";
    cout << "\nTo exit the program enter the character ";
    cin >> numOfElements;
    return 0;
}
