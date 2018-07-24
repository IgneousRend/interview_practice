//Given an array arr[] of n integers,
// find the maximum that maximizes sum of value of
// i*arr[i] where i varies from 0 to n-1.

#include <iostream>
using namespace std;
#define len(A) sizeof(A)/sizeof(A[0])

int max_sum_arr_rot(int A[], int n)
{
    int cumulative = 0;
    int current=0, next =0;
    int res=0;
    for(int i=0; i<n; i++)
    {
        cumulative += A[i];
        current += A[i]*i;
    }

    res = current;

    for(int i=1; i<n; i++)
    {
        next = current - cumulative + A[i-1]*n;
        current = next;
        res = current > res ? current : res;
    }
    return res;
}

int main()
{
    int arr[] = {8, 3, 1, 2};
    int n = len(arr);
    cout << max_sum_arr_rot(arr, n) << endl;
    return 0;
}