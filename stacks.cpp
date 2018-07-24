#include <iostream>

#define max 10
using namespace std;

class Stack {
    int array[max];

public:
    Stack() {
        top = -1;
    }
    int top;
    void push(int x) {
        if (this->top < max)
            this->array[++this->top] = x;
        else
            cout << "Stack Overflow!" << endl;
    }

    int pop() {
        if(this->top >= 0)
            return this->array[top--];
        else
            cout<<"Stack Underflow"<<endl;
    }

    int topVal()
    {
        return this->array[this->top];
    }

    void display()
    {
        if(this->top < 0)
            return;
        for(int i=0; i<=this->top; i++)
        {
            cout<<this->array[i]<<" ";
        }
        cout<<endl;
    }

    bool isEmpty()
    {
        return (this->top < 0);
    }

    static void merge(Stack * S, Stack * T)
    {
        if(S->top + T->top + 2 >= max)
            return;
        while(!T->isEmpty())
            S->push(T->pop());
    }

    void sortStack()
    {
        if(!this->isEmpty())
        {
            int temp = this->pop();
            this->sortStack();
            this->sortedInsert(temp);
        }
    }

    void sortedInsert(int x)
    {
        if(isEmpty() or x > this->array[this->top])
            this->push(x);
        else
        {
            int temp = this->pop();
            sortedInsert(x);
            this->push(temp);
        }
    }
};

void NGE(int A[], int n)
{
    Stack S;
    S.push(A[0]);
    for(int i=1; i<n; i++)
    {
        int current = A[i];
        if(!S.isEmpty())
        {
            int top = S.pop();
            while(current < top)
            {
                cout<<top<<" : "<<current<<endl;
                if(S.isEmpty()) break;
                top = S.pop();

            }

            if(top > current)
                S.push(top);
        }

        S.push(current);
    }

    while(S.isEmpty())
    {
        cout<<S.pop()<<" : "<<-1<<endl;
    }
}

int main()
{
    int a[] = {11, 13, 21, 3};
    NGE(a,4);
    return 0;
}



