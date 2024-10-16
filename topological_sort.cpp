#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// Function to perform topological sorting
void topologicalSort(int V, int adjList[][MAX]) {
    // Step 1: Compute in-degree of all vertices
    int inDegree[MAX] = {0};
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (adjList[u][v] != 0) {
                inDegree[v]++;
            }
        }
    }

    // Step 2: Initialize a queue and enqueue all vertices with in-degree 0
    queue<int> q;
    for (int u = 0; u < V; ++u) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }

    // Step 3: Initialize count of visited vertices
    int count = 0;

    // Step 4: Process vertices and enqueue their adjacent vertices
    int topoOrder[MAX];
    int index = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder[index++] = u; // Store the current vertex in the topological order

        // Iterate through all adjacent vertices of u
        for (int v = 0; v < V; ++v) {
            if (adjList[u][v] != 0) {
                // Decrease in-degree of adjacent vertex
                inDegree[v]--;
                // If in-degree becomes zero, add it to queue
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        count++;
    }

    // Step 5: Check if topological sort is possible
    if (count != V) {
        cout << "Graph contains cycle. Topological sorting not possible." << endl;
        return;
    }

    // Step 6: Print the topological order
    cout << "Topological Order: ";
    for (int i = 0; i < index; ++i) {
        cout << topoOrder[i];
        if (i != index - 1)
            cout << " --> ";
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices (V) and edges (E): ";
    cin >> V >> E;

    // Step 1: Create adjacency list representation of the graph
    int adjList[MAX][MAX];
    memset(adjList, 0, sizeof(adjList));

    cout << "Enter the edges (format: start end):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u][v] = 1; // Set the adjacency matrix entry to 1 to indicate an edge
    }

    // Step 2: Perform topological sorting
    topologicalSort(V, adjList);

    return 0;
}

/*
6 6

5 2
5 0
4 0
4 1
2 3
3 1

*/
