//Lomuto's partition, and Hoare's partition

#include <iostream>

#define len(A) sizeof(A)/sizeof(A[0])
using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int lomuto_partition(int A[], int L, int R) {
    int pivot = A[R];
    int index = L - 1;

    for (int current = L; current <= R - 1; current++) {
        if (A[current] <= pivot)
            swap(&A[++index], &A[current]);
    }
    swap(&A[index + 1], &A[R]);
    return index + 1;
}

int hoare_partition(int A[], int L, int R) {
    int pivot = A[L];
    int i = L - 1, j = R + 1;

    while (true) {
        do {
            i++;
        } while (pivot > A[i]);

        do {
            j--;
        } while (pivot < A[j]);

        if (i >= j) return j;
        swap(&A[i], &A[j]);

    }
}

void quick_sort(int A[], int L, int R) {
    if (L < R) {
        int partition_index = hoare_partition(A, L, R);
        quick_sort(A, L, partition_index - 1);
        quick_sort(A, partition_index + 1, R);
    }
}


int main() {
    int Arr[] = {54, 32, 67, 31, 10, 78, 46, 89, 101, 98};
    int n = len(Arr);
    quick_sort(Arr, 0, n - 1);
    printArray(Arr, n);
    return 0;
}