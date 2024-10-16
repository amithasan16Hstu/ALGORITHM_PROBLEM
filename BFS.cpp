#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100;

void BFS(int adjList[][MAX_NODES], int numNodes, int startNode) {
    bool visited[MAX_NODES] = {false};
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout << "Breadth-First Search starting from node " << startNode << ":" << endl;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Visited node: " << node << endl;

        for (int i = 0; i < numNodes; ++i) {
            if (adjList[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
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
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u][v] = 1;
        adjList[v][u] = 1; // Assuming undirected graph
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    BFS(adjList, numNodes, startNode);

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
