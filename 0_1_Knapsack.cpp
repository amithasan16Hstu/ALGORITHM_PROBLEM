#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int K[101][101] = {0}; // Adjust the size as needed

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    cout << "Dynamic Programming Table (K):" << endl;
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            cout << K[i][w] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return K[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int wt[100], val[100]; // Adjust size as needed
    cout << "Enter the weights of the items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter the values of the items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    cout << endl;

    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;

    return 0;
}

/*
3

10 20 30

60 100 120

50
*/
