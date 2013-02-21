#include <cstdlib>
#include <iostream>
#include <fstream>

#include "graph.h"

using namespace std;

int main()
{
    ifstream text("input.txt");
    if (!text)
    {
        cerr << "Error reading a file" << endl;
        getchar();
        return 1;
    }
    
    cout << "This program counts connected components of directed graph" << endl << endl;
    
    int numOfVertex = 0;
    int numOfWays = 0;
    
    text >> numOfVertex >> numOfWays;
    
    bool **matrix = matrixAdjacency(numOfWays, numOfVertex, text);
    cout << "Matrix of adjacency of graph:" << endl;
    printMatrix(numOfVertex, matrix);
    
    matrix = matrixSymmetric(numOfVertex, matrix);
    matrix = matrixReachability(numOfVertex, matrix);

    int numOfCC = 0;
    numOfCC = numOfConnectedComponent(numOfVertex, matrix);
    
    cout << "The number of connected components is " << numOfCC << endl << endl;
    cout << "To exit the program enter the character ";
    cin >> numOfCC;
    
    removeMatrix(numOfVertex, matrix);
    text.close();
    
    return 0;
}
