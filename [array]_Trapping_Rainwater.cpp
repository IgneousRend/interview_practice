#include<iostream>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        int * a = new int[n];
        for(int i=0; i<n; i++)
            cin >> a[i];
        int left = 0, right = n-1, lMax = 0, rMax = 0;
        int vol = 0;
        while(left < right)
        {
            if(a[left] < a[right])
            {
                if(a[left] > lMax)
                    lMax = a[left];
                else
                    vol += lMax - a[left];
                left++;            
            }
            else
            {
                if(a[right] > rMax)
                    rMax = a[right];
                else
                    vol += rMax - a[right];
                right--;
            }
        }
        cout<<vol<<endl;
        delete(a);
    }
    return 0;
}