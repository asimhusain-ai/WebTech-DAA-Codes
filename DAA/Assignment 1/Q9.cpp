#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void countingSort(int arr[], int n) {
    int maxVal = *max_element(arr, arr + n); // Find the maximum value
    vector<int> count(maxVal + 1, 0); // Initialize count array
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index++] = i; // Place the element in sorted order
            count[i]--;
        }
    }
}
int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}