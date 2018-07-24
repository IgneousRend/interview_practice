#include<iostream>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n, x, s1, s2=0;
		cin>>n;
		s1 = n*(n+1)/2;
		n--;
		while(n--)
		{
			cin>>x;
			s2 += x;
		}
		cout<<s1-s2<<endl;
	}
	return 0;
}