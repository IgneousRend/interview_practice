//Given an array, segregate odd and even numbers
#include <iostream>

#define len(A) (sizeof(A)/sizeof(A[0]))
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void segregate_odd_even(int A[], int n) {
    int i = -1, j = n;
    while (true) {
        do {
            i++;
        } while (A[i] % 2 == 0);

        do {
            j--;
        } while (A[j] % 2 != 0);
        if (i >= j) break;
        swap(&A[i], &A[j]);

    }
}

int main() {
    int Arr[] = {54, 32, 67, 31, 10, 78, 46, 89, 101, 98};
    int n = len(Arr);
    segregate_odd_even(Arr, n);
    printArray(Arr, n);
    return 0;
}

