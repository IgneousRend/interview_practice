#include<iostream>
#include<algorithm>
#define dog int tc; cin>>tc; while(tc--)
#define cat int n;cin>>n;int * a=new int[n];
#define wolf for(int i=0;i<n;i++)cin>>a[i];
using namespace std;

int main()
{
	dog
	{
		cat
		wolf
		for(int i=0; i<n; i++)
			a[i] *= a[i];
		sort(a, a+n);
		int f=0;
		for(int i = n-1; i >= 2; i--)
		{
			int l=0, r=i-1;
			while(l < r)
			{
				if(a[l] + a[r] == a[i])
				{
					f=1; break;
				}
				else if(a[l] + a[r] < a[i])
					l++;
				else
					r--;
			}
			if(f==1) break;
		}
		if(f==1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		delete(a);
	}
	return 0;
}