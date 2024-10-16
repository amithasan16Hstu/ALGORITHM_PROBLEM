#include <bits/stdc++.h>
using namespace std;

const int INF = 999999; 

int d[10][10], a[10][10], n; 
void path() {
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = a[i][j];

    cout<<endl;
    for (int k = 0; k < n; k++) { 
        cout << "Step " << k + 1 << ":" << endl;
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) { 
                
                if (d[i][k] < INF && d[k][j] < INF && d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
                
                cout << d[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << endl;

    cout << "Enter the adjacency matrix (use " << INF << " for infinity):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    path(); 
    
    cout << "The final shortest distances matrix:" << endl;
    cout<<"-----------------------------------------"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == INF)
                cout << "INF\t";
            else
                cout << d[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
/*
4
0 5 999999 10
999999 0 3 999999
999999 999999 0 1
999999 999999 999999 0


*/