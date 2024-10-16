#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int find(vector<Subset> subsets, int i);
void Union(vector<Subset> subsets, int x, int y);
void printMST(vector<Edge> result);

bool compareEdges(const Edge e1, const Edge& e2) {
    return e1.weight < e2.weight;
}


void KruskalMST(vector<Edge> edges, int V) {
    vector<Edge> result; 
    int e = 0; 
    int i = 0;

    
    sort(edges.begin(), edges.end(), compareEdges);

   
    vector<Subset> subsets(V);
    
    
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    
    while (i < V - 1 && e < edges.size()) {
        
        Edge next_edge = edges[e++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

       
        if (x != y) {
            result.push_back(next_edge);
            Union(subsets, x, y);
            i++;
        }

        cout<<"\n----------------------"<<endl;
        cout << "Step " << i << ":" << endl;
        printMST(result);
        cout << endl;
    }

    
    cout << "Minimum Spanning Tree (MST) using Kruskal's Algorithm:" << endl;
    printMST(result);
}


int find(vector<Subset> subsets, int i) {
    
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}


void Union(vector<Subset> subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void printMST(vector<Edge> result) {
    for (const Edge& edge : result) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;
    cout << endl;

    vector<Edge> edges(E);
    cout << "Enter the edges as 'src dest weight':\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    KruskalMST(edges, V);

    return 0;
}
/*
4 5

0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
*/