#include <iostream>
#include <vector>
using namespace std;

void swap(char * a, char * b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void reverse(char * a, char * b)
{
    while(a<b)
    {
        swap(a,b);
        a++,b--;
    }
}

void reverseWords(char *s, char c)
{
    char *word_begin = NULL;
    char *temp = s;
    while( *temp )
    {
        if (( word_begin == NULL ) && (*temp != c) )
            word_begin=temp;

        if( word_begin && ( *(temp+1) == c
                         || *(temp+1) == '\0' ) )
        {
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    }
    reverse(s,temp-1);
    // This is used to reverse the entire string,
    // after individual words have been reversed.
}

int main()
{
    int tc; cin >> tc;
    while(tc--)
    {
        char * s = new char [200];
        cin>>s;
        reverseWords(s,'.');
        cout<<s<<endl;
        delete(s);
    }
    return 0;
}