#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // for INT_MAX

#define V 6 // number of vertices

// Function to find the vertex with minimum distance not yet included in shortest path tree
int miniDist(int distance[], bool Tset[]) {
    int minimum = INT_MAX, index = -1;

    for (int k = 0; k < V; k++) {
        if (!Tset[k] && distance[k] <= minimum) {
            minimum = distance[k];
            index = k;
        }
    }
    return index;
}

// Dijkstra's Algorithm using adjacency matrix
void DijkstraAlgo(int graph[V][V], int src) {
    int distance[V];   // Distance from source to each vertex
    bool Tset[V];      // True if vertex is included in shortest path tree

    // Initialize distances and Tset
    for (int k = 0; k < V; k++) {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0; // Distance to source is 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int m = miniDist(distance, Tset);

        if (m == -1)
            break; // No more reachable vertices

        Tset[m] = true;

        for (int j = 0; j < V; j++) {
            // Update distance[j] if m is connected and results in shorter path
            if (!Tset[j] && graph[m][j] && distance[m] != INT_MAX &&
                distance[m] + graph[m][j] < distance[j]) {
                distance[j] = distance[m] + graph[m][j];
            }
        }
    }

    // Print the results
    printf("Vertex\t\tDistance from Source\n");
    for (int k = 0; k < V; k++) {
        char vertex = 'A' + k;
        if (distance[k] == INT_MAX)
            printf("%c\t\t\t8\n", vertex);
        else
            printf("%c\t\t\t%d\n", vertex, distance[k]);
    }
}

int main() {
    printf("\tCompiled by Sarfraj Alam\n");

    int graph[V][V] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };

    DijkstraAlgo(graph, 0); // Starting from vertex A (index 0)

    return 0;
}
