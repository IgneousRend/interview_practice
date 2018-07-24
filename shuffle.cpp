// Created by Agnihotra on 13-06-2018.
// Shuffle an array / Yates-Fisher Algo

#include <iostream>
#include <time.h>

#define len(A) (sizeof(A)/sizeof(A[0]))
using namespace std;

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void shuffle(int A[], int n)
{
    srand(time(NULL));
    for(int i=n-1; i>0; i--)
    {
        int j = rand() % (i+1);
        swap(A[i],A[j]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    shuffle(arr, n);
    printArray(arr, n);

    return 0;
}