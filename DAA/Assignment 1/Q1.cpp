#include <iostream>
using namespace std;
int main() {
    int arr[] = {3, 7, 1, 9, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target, index = -1;
    cout << "Enter the number to search: ";
    cin >> target;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            index = i;
            break;
        }
    }
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}