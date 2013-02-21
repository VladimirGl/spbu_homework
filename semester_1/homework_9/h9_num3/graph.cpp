#include <iostream>
#include <fstream>
#include "graph.h"

bool ** matrixAdjacency(int numOfWays, int numOfVertex, ifstream &text) {
    bool **adjacency = new bool*[numOfVertex];
    
    for (int i = 0; i < numOfVertex; i++)
        adjacency[i] = new bool[numOfVertex];
        
    for (int i = 0; i < numOfVertex; i++) {
        for (int j = 0; j < numOfVertex; j++) {
            if (i == j)
                adjacency[i][j] = true;
            else
                adjacency[i][j] = false;
        }
    }
            
    int firstVertex = 0;
    int secondVertex = 0;
    int len = 0;
    
    for (int i = 0; i < numOfWays; i++) {
        text >> firstVertex >> secondVertex >> len;
        adjacency[firstVertex - 1][secondVertex - 1] = true;
    }
    
    return adjacency;
}

bool ** matrixReachability(int numOfVertex, bool **adjacency) {
    for (int k = 0; k < numOfVertex; k++)
        for (int i = 0; i < numOfVertex; i++)
            for (int j = 0; j < numOfVertex; j++)
                adjacency[i][j] = adjacency[i][j] || (adjacency[i][k] && adjacency[k][j]);
    
    return adjacency;
}

bool ** matrixSymmetric(int numOfVertex, bool **adjacency) {
    for (int i = 0; i < numOfVertex; i++)
        for (int j = 0; j < numOfVertex; j++)
            if (adjacency[i][j] == true) 
                adjacency[j][i] = true;
                 
    return adjacency;
}

int numOfConnectedComponent(int numOfVertex, bool **adjacency) {
    int counter = 0;
    for (int k = 0; k < numOfVertex; k++) {
        bool flag = true;
        for (int i = k; i < numOfVertex; i++) {
            if (adjacency[i][k] == true) {
                for (int j = k; j < numOfVertex; j++) {
                    adjacency[i][j] = false;
                }
            flag = false;
            }
        }
        if (!flag)
            counter++;
    }
    return counter;
} 

void printMatrix(int numOfVertex, bool **adjacency) {
     for (int i = 0; i < numOfVertex; i++) {
         for (int j = 0; j < numOfVertex; j++)
             cout << adjacency[i][j] << " ";
         cout << endl;
     }
}

void removeMatrix(int numOfVertex, bool **adjacency) {
     for (int i = 0; i < numOfVertex; i++) {
         delete[] adjacency[i];
     }
     delete[] adjacency;
}

        
