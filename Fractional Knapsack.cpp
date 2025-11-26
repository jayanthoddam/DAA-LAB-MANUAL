#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    float value[100], weight[100];

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }

    float capacity;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Calculate value/weight ratio
    float ratio[100];
    for (int i = 0; i < n; i++) {
        ratio[i] = value[i] / weight[i];
    }

    // Sort by ratio in descending order (simple bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                swap(ratio[j], ratio[j + 1]);
                swap(value[j], value[j + 1]);
                swap(weight[j], weight[j + 1]);
            }
        }
    }

    float maxValue = 0;

    // Greedy selection
    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (weight[i] <= capacity) {
            maxValue += value[i];
            capacity -= weight[i];
        } else {
            float fraction = capacity / weight[i];
            maxValue += value[i] * fraction;
            capacity = 0;
        }
    }

    cout << "Maximum value: " << maxValue;

    return 0;
}
