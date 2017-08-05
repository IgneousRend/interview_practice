#include <iostream>
#include <vector>
using namespace std;

void reverse(char * a, char * b)
{
    while(a<b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
        a++,b--;
    }
}

void reverseWords(char *s)
{
    char *word_begin = NULL;
    char *temp = s;
    while( *temp )
    {
        if (( word_begin == NULL ) && (*temp != ' ') )
            word_begin=temp;

        if( word_begin && ( *(temp+1) == ' '
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
    char s[] = "Dragon in the making";
    reverseWords(s);
    cout<<s;
    return 0;
}
