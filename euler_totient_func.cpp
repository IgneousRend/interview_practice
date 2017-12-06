#include <iostream>
using namespace std;

unsigned long long eulertotient (int n)
{
    float result = n;
    for (int p=2; p*p <= n; p++)
    {
        if(n%p == 0)
        {
            while (n % p == 0)
                n /= p;
            result *= 1.0 - 1.0 / (float) p;
        }
    }
    if (n > 1)
        result *= 1.0 - (1.0 / (float) n);
    return result;
}

int main()
{
    int x;
    //cin>>x;
    for(int i =1;i<10;i++)
    cout<<eulertotient(i)<<" ";
    return 0;
}
