# Graph Theory and Dijkstra's Algorithm Implementation

This project implements a graph data structure and Dijkstra's algorithm for finding shortest paths in undirected graphs. The implementation includes functionality for creating graphs, computing adjacency matrices, identifying odd-degree vertices, and running Dijkstra's shortest path algorithm.

## Project Overview

The application is designed to:
1. Read a graph definition from standard input
2. Create an adjacency matrix representation of the graph
3. Identify vertices with odd degrees
4. Apply Dijkstra's algorithm to find shortest paths from odd-degree vertices to all other vertices

## Components

- **Graph**: Manages the adjacency matrix and vertices
- **Vertex**: Represents graph nodes with index and degree properties
- **Edge**: Represents connections between vertices

## File Structure

- `Main.cpp`: Entry point that coordinates the execution of tasks
- `Graph.h/cpp`: Implementation of the Graph class and algorithms
- `Vertex.h/cpp`: Definition and implementation of the Vertex class
- `Edge.h/cpp`: Definition and implementation of the Edge class
- `Makefile`: Compilation instructions
- `test_cases/`: Contains sample graph definitions for testing

## Compilation

To compile the project, run:

```
make
```

This will create an executable named `dijkstra`.

To clean the compiled files:

```
make clean
```

## Usage

The program reads graph information from standard input. The input format is:

```
<number_of_vertices> <number_of_edges>
<start_vertex_1> <end_vertex_1>
<start_vertex_2> <end_vertex_2>
...
<start_vertex_n> <end_vertex_n>
```

Example usage with a test case:

```
./dijkstra < test_cases/small-network.txt
```

## Output

The program outputs:
1. The adjacency matrix of the graph
2. The list of vertices with odd degrees
3. For each odd-degree vertex, the shortest path distances to all other vertices

## Example Test Cases

Several test cases are provided in the `test_cases/` directory:
- `small-network.txt`: A simple network with 8 vertices and 11 edges
- `eco-florida.txt`: A larger ecological network
- `chords.txt`: A graph representing chord connections
- `square-in-square.txt`: A geometric graph structure
- `all-odd.txt`: A graph where all vertices have odd degrees
- `triangle-in-triangle.txt`: A nested triangle structure

## Algorithm Details

- The adjacency matrix uses a binary representation where 1 indicates an edge between vertices
- Dijkstra's algorithm implementation uses an array-based approach for simplicity
- The program efficiently identifies odd-degree vertices by counting edge connections

## Author
This project was created in a team by: 
1. Ayush Sachin Wattamwar
2. Hridaya Amol Dande
This project was developed as part of a graph theory and algorithms implementation exercise. 
