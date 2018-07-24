#include<iostream>
using namespace std;

class Stack 
{
	char A[101];
	public:
	int top;
	Stack()
	{
		top = -1;
	}

	void push(char c)
	{
		A[++top] = c;
	}

	char pop()
	{
		return A[top--];
	}

	char topVal()
	{
		return A[top];
	}

	bool isEmpty()
	{
		return (top<0);
	}
};

bool balanced(char * s)
{
	Stack stack;
	while(*s != '\0')
	{
		if(*s == '{' or *s == '(' or *s == '[')
			stack.push(*s);
		else
		{
			if(stack.topVal() == '{' and *s == '}'
				or stack.topVal() == '(' and *s == ')'
				or stack.topVal() == '[' and *s == ']')
					stack.pop();
			else
				return false;
		}
		s++;
	}
	if(stack.isEmpty())
		return true;
}

int main()
{
	int tc; cin >> tc;
	while(tc--)
	{
		char * s = new char[101];
		cin >> s;
		if(balanced(s))
			cout<<"balanced"<<endl;
		else
			cout<<"not balanced"<<endl;
	}
	return 0;
}
