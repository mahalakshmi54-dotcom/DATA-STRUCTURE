#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int temp[100];
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[] = {25, 10, 45, 30, 15, 50, 20};
    int n = 7;

    mergeSort(a, 0, n - 1);

    cout << "Sorted weights: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
    return 0;
}
