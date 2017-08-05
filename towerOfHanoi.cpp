#include<iostream>
using namespace std;

void HanoiRecursive(int n, char from, char aux, char to)
{
    if (n==1)
    {
        printf("Move disc: 1| From: %c| To: %c \n",from,to);
        return;
    }
    HanoiRecursive(n-1,from,to,aux);
    printf("Move disc: %d| From: %c| To: %c \n",n,from,to);
    HanoiRecursive(n-1,aux,from,to);
}

int main()
{
    int n=4;
    HanoiRecursive(n,'A','B','C');
    return 0;
}
