#include <bits/stdc++.h>
using namespace std;

const int INF = 999999; 

int minDistance(int dist[], bool visited[], int n) {
    int minDist = INF, minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(int graph[][100], int src, int n) {
    int dist[100];
    bool visited[100];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }

        cout << "Step " << count + 1 << ":" << endl;
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF)
                cout << "INF\t";
            else
                cout << dist[i] << "\t";
        }
        cout << endl << endl;
    }

    cout << "Shortest distances from source vertex " << src << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[100][100];
    cout << "Enter the adjacency matrix (use 0 for no connection, " << INF << " for infinity):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int src;
    cout << "Enter the source vertex (0 to " << n - 1 << "): ";
    cin >> src;

    dijkstra(graph, src, n);

    return 0;
}

/*
5
0 10 5 999999 999999
999999 0 2 1 999999
999999 3 0 9 2
999999 999999 999999 0 4
7 999999 999999 6 0

0




*/
