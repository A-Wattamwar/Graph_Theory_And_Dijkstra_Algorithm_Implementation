#include "Graph.h"

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    this->numEdges = 0;
    
    // Initialize adjacency matrix
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    
    // Initialize vertices
    vertices = new Vertex[numVertices];
    for (int i = 0; i < numVertices; i++) {
        vertices[i].setIndex(i + 1);
        vertices[i].setDegree(0);
    }
}

// Free memory
Graph::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] vertices;
}

void Graph::addEdge(Edge* edge) {
    int start = edge->getStartVertex() - 1; 
    int end = edge->getEndVertex() - 1;     
    
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
    
    // Update vertex degrees
    vertices[start].setDegree(vertices[start].getDegree() + 1);
    vertices[end].setDegree(vertices[end].getDegree() + 1);
    
    numEdges++;
}

void Graph::printAdjMatrix() {
    std::cout << "The adjacency matrix of G:" << std::endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            std::cout << adjMatrix[i][j];
            if (j < numVertices - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int* Graph::findOddDegreeVertices(int& count) {
    // Count odd vertices
    count = 0;
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i].getDegree() % 2 != 0) {
            count++;
        }
    }
    
    int* oddVertices = new int[count];
    
    // Fill array
    int index = 0;
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i].getDegree() % 2 != 0) {
            oddVertices[index++] = vertices[i].getIndex();
        }
    }
    
    return oddVertices;
}

int* Graph::dijkstra(int source) {
    // Convert to 0-indexed
    int src = source - 1;
    
    int* dist = new int[numVertices];
    bool* visited = new bool[numVertices];
    
    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    
    // Distance to source is 0
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < numVertices - 1; count++) {
        // Find vertex with minimum distance
        int minDist = INT_MAX;
        int minIndex = -1;
        
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        visited[minIndex] = true;
        
        // Update dist value of adjacent vertices
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && adjMatrix[minIndex][v] && 
                dist[minIndex] != INT_MAX && 
                dist[minIndex] + adjMatrix[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + adjMatrix[minIndex][v];
            }
        }
    }
    
    delete[] visited;
    return dist;
} 