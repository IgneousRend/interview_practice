#include <iostream>

using namespace std;

void merge(int A[], int L, int M, int R) {
    int i, j, k, n1 = M - L + 1, n2 = R - M;
    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = A[L + i];
    for (j = 0; j < n2; j++)
        right[j] = A[M + 1 + j];

    i = j = 0, k = L;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            A[k++] = left[i++];
        else
            A[k++] = right[j++];
    }

    while (i < n1)
        A[k++] = left[i++];
    while (j < n2)
        A[k++] = right[j++];
}

void merge_sort(int A[], int L, int R) {
    int M = L + (R - L) / 2;
    if (L < R) {
        merge_sort(A, L, M);
        merge_sort(A, M + 1, R);
        merge(A, L, M, R);
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    int Arr[] = {54, 32, 67, 31, 10, 78, 46, 89, 101, 98};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    printArray(Arr, size);
    merge_sort(Arr, 0, size - 1);
    printArray(Arr, size);

    return 0;
}
