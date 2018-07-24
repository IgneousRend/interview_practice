#include<iostream>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n, sum, total=0, start=0, end, flag=0;
		cin>>n>>sum;
		int * a = new int[n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		
		for(int i=0; i<n; i++)
		{
			total += a[i];
			while(total > sum)
				total -= a[start++];
			if(total == sum)
			{
				end = i;
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			cout<<start+1<<" "<<end+1<<endl;
		else
			cout<<-1<<endl;
		delete(a);		
	}

	return 0;
}