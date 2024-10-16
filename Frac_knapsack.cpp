#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
    double valuePerWeight;
};

bool cmp(Item a, Item b) {
    return a.valuePerWeight > b.valuePerWeight;
}

double fractionalKnapsack(int W, Item items[], int n) {
    sort(items, items + n, cmp);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
            cout << "Take 100% of item " << i + 1 << endl;
        } else {
            int remainingWeight = W - currentWeight;
            double fraction = (double) remainingWeight / items[i].weight;
            totalValue += items[i].value * fraction;
            cout << "Take " << fraction * 100 << "% of item " << i + 1 << endl;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    Item items[100]; // Adjust size as needed
    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].valuePerWeight = (double) items[i].value / items[i].weight;
    }

    cout << endl;

    double maxValue = fractionalKnapsack(W, items, n);

    cout << "\nTotal maximum value in Knapsack = " << maxValue << endl;

    return 0;
}

/*
4
50

10 60
20 100
30 120
40 150

*/
