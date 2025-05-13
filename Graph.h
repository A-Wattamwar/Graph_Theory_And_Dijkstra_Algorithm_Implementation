#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include "Edge.h"
#include <iostream>
#include <climits>

class Graph {
private:
    int numVertices;
    int numEdges;
    int** adjMatrix;
    Vertex* vertices;

public:
    Graph(int numVertices);
    ~Graph();
    
    void addEdge(Edge* edge);
    void printAdjMatrix();
    int* findOddDegreeVertices(int& count);
    int* dijkstra(int source);
};

#endif 