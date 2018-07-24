#include<iostream>
using namespace std;

int main()
{
	int tc; 
	cin>>tc;
	while(tc--)
	{
		int n; 
		cin>>n;
		int * a = new int[n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		int l=0, r=n-1;
		int ls=a[l], rs=a[r];
		while(l<=r)
		{
			if(ls<rs)
			{
				l++;
				ls += a[l];
			}
			else if(rs<ls)
			{
				r--;
				rs += a[r];
			}
			else
				break;

		}
		if(l<=r)
			cout<<(l+r+2)/2<<endl;
		else
			cout<<-1<<endl;
		delete(a);


	}
	return 0;
}