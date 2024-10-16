#include <bits/stdc++.h>
using namespace std;


struct Edge {
    int src, dest, weight;
};

void PrimMST(vector<vector<int>> graph, int V);

int minKey(vector<int> key, vector<bool> mstSet, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(vector<int> parent, vector<vector<int>> graph, int V) {
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}


void PrimMST(vector<vector<int>> graph, int V) {
    vector<int> parent(V); 
    vector<int> key(V, INT_MAX); 
    vector<bool> mstSet(V, false); 

    
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    
    key[0] = 0; 
    parent[0] = -1; 

    
    for (int count = 0; count < V - 1; count++) {
        
        int u = minKey(key, mstSet, V);

        
        mstSet[u] = true;

        
        for (int v = 0; v < V; v++) {
            
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }

        
        cout << "Step " << count + 1 << ":" << endl;
        printMST(parent, graph, V);
        cout << endl;
    }

    
    cout << "Minimum Spanning Tree (MST) using Prim's Algorithm:" << endl;
    printMST(parent, graph, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices (V): ";
    cin >> V;

    
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (0 for no edge, weight otherwise):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }


    PrimMST(graph, V);

    return 0;
}

/*
5

0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0


*/