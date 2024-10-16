#include <bits/stdc++.h>
using namespace std;


int MCM(int p[], int n) {
    int m[n][n];
    
    
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

   
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }

            
            cout << "M[" << i << "][" << j << "] = " << m[i][j] << endl;
        }
    }
    
    return m[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int arr[n];
    cout << "Enter the dimensions of matrices (including result matrix): ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Minimum number of multiplications is " << MCM(arr, n) << endl;

    return 0;
}
/*
4
10 30 5 60 4 (10x30, 30x5, 5x60, 60x4)
*/