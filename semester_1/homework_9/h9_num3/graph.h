#ifndef _GRAPH_H_
#define _GRAPH_H_

using namespace std;

bool ** matrixAdjacency(int numWays, int numOfVertex, ifstream &text);
bool ** matrixReachability(int numOfVertex, bool **adjacency);
bool ** matrixSymmetric(int numOfVertex, bool **adjacency);
int numOfConnectedComponent(int numOfVertex, bool **adjacency);
void removeMatrix(int numOfVertex, bool **adjacency);
void printMatrix(int numOfVertex, bool **adjacency);

#endif
