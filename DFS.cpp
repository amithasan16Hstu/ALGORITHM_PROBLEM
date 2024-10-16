#include <bits/stdc++.h>
using namespace std;
const int MAX_NODES = 100;

void DFS(int node, int adjList[][MAX_NODES], bool visited[], int numNodes) {
    visited[node] = true;
    cout << "Visited node: " << node << endl;

    for (int i = 0; i < numNodes; i++) {
        if (adjList[node][i] && !visited[i]) {
            DFS(i, adjList, visited, numNodes);
        }
    }
}

void DFS(int adjList[][MAX_NODES], int startNode, int numNodes) {
    bool visited[MAX_NODES] = {false};

    cout << "Depth-First Search starting from node " << startNode << ":" << endl;
    DFS(startNode, adjList, visited, numNodes);
    cout << endl;
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    int adjList[MAX_NODES][MAX_NODES] = {0};

    cout << "Enter the edges (format: start end):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u][v] = 1;
        adjList[v][u] = 1; // Assuming undirected graph
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    DFS(adjList, startNode, numNodes);

    return 0;
}

/*
5
6

0 1
0 2
1 3
1 4
2 4
3 4

0
*/
