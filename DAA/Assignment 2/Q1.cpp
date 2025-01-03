#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

bool compare(const Item& a, const Item& b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    for (const Item& item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    cout << "Maximum value in the knapsack = " << fractionalKnapsack(capacity, items) << endl;
    return 0;
}
