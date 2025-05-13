#include "Edge.h"
#include "Graph.h"
#include <iostream>

int main(){
    int numOfVertices;
    int numOfEdges;

    if(!std::cin.eof()){
        std::cin >> numOfVertices;
        std::cin >> numOfEdges;
    }
    else{
        std::cout<<"Input not found!"<<std::endl;
        return 1;
    }

    // Create graph
    Graph* graph = new Graph(numOfVertices);

    // Load edges
    for(int i = 0; i < numOfEdges && !std::cin.eof(); i++){
        int startVertice;
        int endVertice;
        std::cin >> startVertice;
        std::cin >> endVertice;
        Edge* newEdge = new Edge(startVertice, endVertice);
        graph->addEdge(newEdge);
        delete newEdge;
    }

    // Task 1: Print adjacency matrix
    graph->printAdjMatrix();
    std::cout << std::endl;

    // Task 2: Find and print odd degree vertices
    int oddCount;
    int* oddVertices = graph->findOddDegreeVertices(oddCount);
    
    std::cout << "The odd degree vertices in G:" << std::endl;
    std::cout << "O = { ";
    for(int i = 0; i < oddCount; i++){
        std::cout << oddVertices[i];
        if(i < oddCount - 1){
            std::cout << " ";
        }
    }
    std::cout << " }" << std::endl << std::endl;

    // Task 3: Run Dijkstra's algorithm for each odd degree vertex
    for(int i = 0; i < oddCount; i++){
        int source = oddVertices[i];
        int* distances = graph->dijkstra(source);
        
        std::cout << "Single source shortest path lengths from node " << source << std::endl;
        for(int j = 0; j < numOfVertices; j++){
            std::cout << "  " << j + 1 << ": " << distances[j] << std::endl;
        }
        
        if(i < oddCount - 1){
            std::cout << std::endl;
        }
        
        delete[] distances;
    }

    delete[] oddVertices;
    delete graph;

    return 0;
}