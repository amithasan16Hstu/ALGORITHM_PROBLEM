#include <bits/stdc++.h>
using namespace std;


int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    cout << "Partitioning with pivot " << "("<<pivot<<")" << ":" << endl;

    for (int j = low; j <= high - 1; j++) {
        
        if (arr[j] <= pivot) {
            i++; 
            
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    
    cout << "Array after partition: ";
    for (int k = low; k <= high; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    return (i + 1);
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        
        int pi = partition(arr, low, high);

        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    cout<<"------------------------"<<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
