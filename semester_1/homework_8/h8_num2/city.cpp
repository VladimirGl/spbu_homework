#include <iostream>
#include <fstream>
#include "city.h"

int ** createMap(int numCit, int numRds, ifstream &text) {
    int **map = new int*[numCit];
    for (int i = 0; i < numCit; i++) {
        map[i] = new int[numCit];
    }
    for (int i = 0; i < numCit; i++) {
        for (int j = 0; j < numCit; j++) {
            map[i][j] = inf;
        }
    }
    int cityOne = 0;
    int cityTwo = 0;
    int len = 0;
    for (int i = 0; i < numRds; i++) {
        text >> cityOne >> cityTwo >> len;
        map[cityOne - 1][cityTwo - 1] = len;
        map[cityTwo - 1][cityOne - 1] = len;
    }
    return map;
}

void cities(bool *isSeen, City *cityN, int numCit, int *path) {
    for (int i = 1; i < numCit; i++) {
        isSeen[i] = false;
        cityN[i].distance = inf;
        cityN[i].number = i + 1;
        path[i] = -1;
    }
    cityN[0].number = 0;
    path[0] = -1;
    isSeen[0] = false;
    cityN[0].distance = 0;
}

int findMin(bool *isSeen, City *cityN, int numCit) {
    int min = 0;
    for (int i = 1; i < numCit; i++) {
        if (!isSeen[i] && (isSeen[min] || (cityN[i].distance < cityN[min].distance))) {
            min = i;
        }
    }
    return min;
}

void shortestDijkstra(int **map, City *cityN, bool *isSeen, int numCit, int *path) { 
    for (int i = 0; i < numCit; i++) {
        int w = findMin(isSeen, cityN, numCit);
        isSeen[w] = true;
        for (int j = 1; j < numCit; j++) {
            if (!isSeen[j]) {
                if (cityN[j].distance > (cityN[w].distance + map[w][j])) {
                     cityN[j].distance = (cityN[w].distance + map[w][j]);
                     path[j] = w+1;
                }
            }
        }
    }
}         

void printPath(int *path, int number) {
    string str1 = "";
    string str2 = "";
    int j = number;
    str1 = path[j] + '0';
    while (path[j] != 1) {
        j = path[j] - 1;
        str2 = path[j] + '0';
        str1 = str1 + str2;
    }
    for (int i = (str1.length() - 1); i >= 0; i--) {
        cout << str1[i] << " ";
    }
    cout << (number + 1);
    cout << endl;
}

void removeAll(int **map, bool *isSeen, City *cityN, int numCit) {
     delete[] isSeen;
     delete[] cityN;
     for (int i = 0; i < numCit; i++) {
         delete[] map[i];
     }
     delete[] map;
}
