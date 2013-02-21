#ifndef _CITY_H_
#define _CITY_H_

using namespace std;

struct City {
    int distance;
    int number;
};

const int inf = 1000000000;

int ** createMap(int numCit, int numRds, ifstream &text);
void cities(bool *isSeen, City *cityN, int numCit, int *path);
int findMin(bool *isSeen, City *cityN, int numCit);
void shortestDijkstra(int **map, City *cityN, bool *isSeen, int numCit, int *path);
void printPath(int *path, int number);
void removeAll(int **map, bool *isSeen, City *cityN, int numCit);

#endif
