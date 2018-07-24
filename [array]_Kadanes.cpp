#include<iostream>
#include<climits>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n, globalMax = INT_MIN, curMax = 0;
		cin>>n;
		int * a = new int[n];
		for(int i=0; i<n; i++)
			cin>>a[i];

		for(int i=0; i<n; i++)
		{
			curMax += a[i];
			if(curMax > globalMax)
				globalMax = curMax;
			if(curMax < 0)
				curMax = 0;
		}
		cout<<globalMax<<endl;
		delete(a);
	}
	return 0;
}