#include <iostream>
#include <fstream>
#include "city.h"
#include "quikSort.h"

using namespace std;

int main() {
    ifstream text("input.txt");
    if (!text)
    {
        cerr << "Error reading a file" << endl;
        getchar();
        return 1;
    }
    
    cout << "This program displays the number of cities\nin order of capture, "
            "and the distance from\neach captured city, and the path:\n\n"; 
               
    int numCit = 0;
    int numRds = 0;
    text >> numCit >> numRds;
    int **map = createMap(numCit, numRds, text);
    int *path = new int[numCit];
    bool *isSeen = new bool[numCit];
    City *cityN = new City[numCit];
    cities(isSeen, cityN, numCit, path);
    
    shortestDijkstra(map, cityN, isSeen, numCit, path);
    
    quikSort(cityN, 0, numCit - 1);
    
    for (int i = 1; i < numCit; i++) {
        cout << "number of city: " << cityN[i].number << endl;
        if (cityN[i].distance == inf) {
            cout << "isolated city";
            cout << endl << endl;
        } else {
            cout << "distance to city: " << cityN[i].distance << endl;
            cout << "path:" << endl;
            printPath(path, (cityN[i].number - 1));
            cout << endl;
        }
    }
    
    cout << "To exit the program enter the character ";
    cin >> numCit;
    
    removeAll(map, isSeen, cityN, numCit);
    text.close();
    
    return 0;
}
