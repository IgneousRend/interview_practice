//Given an array of non negative integers and a number x,
//find a pair in array whose product is closest to x.

#include <iostream>
#include <algorithm>
#define len(A) (sizeof(A)/sizeof(A[0]))

using namespace std;

void closest_product_pair(int A[], int x, int n)
{
    sort(A,A+n);
    int left = 0, right = n-1, diff = INT_MAX, F1, F2;
    while(left < right)
    {
        int temp = A[left]*A[right];
        if(abs(temp-x) < diff)
        {
            diff = abs(temp-x);
            F1 = A[left];
            F2 = A[right];
        }
        if(temp > x)    right--;
        else            left++;
    }
    cout<<F1<<" x "<<F2<<endl;
}

int main()
{
    int arr[] = { 2, 3, 5, 9 }, x = 8;
    closest_product_pair(arr,x, len(arr));
    return 0;
}