#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = {0};
    for (int num : arr) count[(num / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[--count[(arr[i] / exp) % 10]] = arr[i];
    }
    arr = output;
}

void radixSort(vector<int>& arr) {
    for (int exp = 1, maxVal = *max_element(arr.begin(), arr.end()); maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    for (int num : arr) cout << num << " ";
    return 0;
}
