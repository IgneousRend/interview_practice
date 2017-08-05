#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int x;
    int y;
    Node(int a, int b)
    {
        x = a;
        y = b;
    }
};


int main()
{
    char s[] = "babb baab";         //Matrix; spaces separate rows; b = vertex; a = blank space.
    vector<Node> N;
    int i,j=0,k=0;
    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i] == 'b')
            N.push_back(Node(j,k));
        k++;
        if(s[i] == ' ')
            k=0, j++;
    }
    int count = 0;
    for(i=0; i<N.size() - 1; i++)
    {
        for(j=i+1; j<N.size(); j++)
        {
            if(N[i].x != N[j].x && N[i].y != N[j].y)
            {
                for(k=0; k<N.size(); k++)
                {
                    if(N[k].x == N[i].x && N[k].y == N[j].y)
                        count++;
                    if(N[k].y == N[i].y && N[k].x == N[j].x)
                        count++;
                }
            }
        }
    }

    cout<<count;

    return 0;
}
