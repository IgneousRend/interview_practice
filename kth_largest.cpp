#include <iostream>

using namespace std;
#define len(A) (sizeof(A)/sizeof(A[0]))

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int A[], int L, int R) {
    int pivot = A[R];
    int index = L - 1;

    for (int current = L; current <= R - 1; current++) {
        if (A[current] >= pivot)
            swap(&A[++index], &A[current]);
    }
    swap(&A[index + 1], &A[R]);
    return index + 1;
}

// To pass the whole range of values, use L=0, R = n-1, not n
int kth_largest(int A[], int L, int R, int K)
{
    if (K > 0 && K <= R - L + 1)
    {
        int pos = partition(A, L, R);
        if (pos - L == K-1)
            return A[pos];
        if (pos - L > K-1)
            return kth_largest(A, L, pos-1, K);
        else
            return kth_largest(A, pos+1, R, K-1-pos+L);
    }
}


void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main() 
{
    int tc; cin >> tc;
    while(tc--)
    {
        int n,k; cin >> k >> n;
        int * a = new int[n];
        for(int i = 0; i<n; i++)
        {
            cin>>a[i];
            if (i<k-1)
                cout<<-1<<" ";
            else
                cout<<kth_largest(a,0,i,k)<<" ";

        }
        cout<<endl;

    }

    return 0;
}