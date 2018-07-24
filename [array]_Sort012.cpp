#include<iostream>
using namespace std;

int main()
{
	int tc; cin>>tc;
	while(tc--)
	{
		int n, x, zero=0, one=0, two=0;
		cin>>n;
		while(n--)
		{
			cin>>x;
			if(x==0)	zero++;
			if(x==1)	one++;
			if(x==2)	two++;
		}
		int i;
		for(i=0;i<zero;i++)
			cout<<0<<" ";
		for(i=0;i<one;i++)
			cout<<1<<" ";
		for(i=0;i<two;i++)
			cout<<2<<" ";
		cout<<endl;
	}
	return 0;
}