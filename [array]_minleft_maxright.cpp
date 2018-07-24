#include<iostream>
using namespace std;
int main()
 {
    //code
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int i, a[n];
        for(i = 0; i < n; i++)
            cin >> a[i];
        int max1=a[0],f=0;
        i = 1;
        int j;
        while(i<n-1)
        {
            if(max1<=a[i])
            {
                max1 = a[i];
                j = i+1;
                while(j!=n)
                {
                    if(a[j]>=a[i])
                    {
                        if(a[j] > max1)
                            max1 = a[j];
                        j++;
                    }
                    else{
                        i = j+1;
                        break;
                    }
                }
                if(j == n){
                    f = 1;
                    cout << a[i];
                    break;
                }
            }

            else
                i++;
            
        }
        if(f == 0)
            cout << -1;
        cout << endl;
    }
    return 0;
}