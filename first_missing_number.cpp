#include <iostream>
using namespace std;

int main()
{
    int tc=2;
    while(tc--)
    {
        int n, x, r=0;
        cin>>n;
        for(int i=1; i<n; i++)
        {
            cin>>x;
            if(x != i)
                r = i;
        }
        cout<<r<<endl;
    }
    return 0;
}