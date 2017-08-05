//Asked in Microsoft IDC Coding Interview. 
//Agnihotra Bhattacharya

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a[] = {1,2,3,4,5};      //Set
    int y=2,z=4;                //To print subsets of size between y to z
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<(1<<n);i++)
    {
        int x = i;
        vector<int> v;         //Empty vector to store value of i in binary
        
        //Convert i to binary
        while(x!=0)             
        {
            v.push_back(x%2);
            x = x/2;
        }
        
        //Fill the vector with 0's to ensure there are exactly n-bits
        //n = size(set)
        while(v.size()<n)
            v.push_back(0);
        
        //Reverse the vector; needed for binary conversion.
        reverse(v.begin(),v.end());
        
        //To count the number of set bits
        int count = 0;
        for(int j=0;j<v.size();j++)
        {
            if(v[j]==1)
                count++;
        }
        
        //Print the number in the set corresponding to the set bit
        //if set bits are between y and z
        if(count>=y && count<=z)
        {
            for (int j = 0; j < v.size(); j++) {
                if (v[j] == 1)
                    cout << a[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
