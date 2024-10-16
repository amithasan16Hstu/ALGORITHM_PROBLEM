#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int source, destination, weight;
};

void bellmanFord(Edge edges[], int V, int E, int start) {
    int distance[100];
    for (int i = 0; i < V; ++i) {
        distance[i] = INT_MAX;
    }
    distance[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }

        cout << "After iteration " << i + 1 << ":" << endl;
        cout << "Vertex Distance from Source" << endl;
        for (int k = 0; k < V; k++) {
            if (distance[k] == INT_MAX)
                cout << k << "\t\t" << "INF" << endl;
            else
                cout << k << "\t\t" << distance[k] << endl;
        }
        cout << endl;
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].source;
        int v = edges[j].destination;
        int weight = edges[j].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout << "Final Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        if (distance[i] == INT_MAX)
            cout << i << "\t\t" << "INF" << endl;
        else
            cout << i << "\t\t" << distance[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    Edge edges[100];
    cout << "Enter the edges as source destination weight:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    bellmanFord(edges, V, E, start);

    return 0;
}

/*
5 8

0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3

0

*/
