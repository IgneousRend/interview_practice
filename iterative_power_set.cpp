#include <iostream>
#include <math.h>
using namespace std;

void printPowerSets(char str[], int n)
{
    unsigned int m = pow(2,n);
    for(int i=1; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i & (1<<j))
                cout<<str[j];
        }
        cout<<endl;
    }
}

int main()
{
    char set[] = {'a','b','c'};
    printPowerSets(set,3);
    return 1;
}
