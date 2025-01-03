#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    for (int i = 0, j = 0, k = l; k <= r; k++)
        arr[k] = (j >= n2 || (i < n1 && L[i] <= R[j])) ? L[i++] : R[j++];
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    mergeSort(arr, 0, 5);
    for (int x : arr) cout << x << " ";
    return 0;
}