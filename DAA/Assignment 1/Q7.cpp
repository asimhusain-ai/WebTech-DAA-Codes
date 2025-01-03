#include <iostream>
using namespace std;
int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);  // Swap the minimum element with the first element
    }
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}