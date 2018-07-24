#include<iostream>
using namespace std;

class CLL
{
    int value;
    CLL * next;
public:
    CLL()
    {
        next = NULL;
    }

    CLL(int x)
    {
        next = this;
        value = x;
    }

    void display()
    {
        CLL * node = this;
        CLL * head = this;
        do{
            cout<<node->value<<" ";
            node = node->next;
        }while(node != head);
    }

    void insert(int x)
    {
        CLL * head = this;
        CLL * node = this;
        do{
            node = node->next;
        }while(node->next != head);

        node->next = new CLL(x);
        node->next->next = head;
    }

    void swapFirstLast(CLL * &head)
    {
        CLL * one = head;
        CLL * two = head;
        do{
            one = two;
            two = two->next;
        }while(two->next != head);
        one->next = head;
        two->next = head->next;
        one->next->next = two;
        head = two;
    }


};


int main()
{
    CLL * A = new CLL(0);
    A->insert(1);
    A->insert(2);
    A->insert(3);
    A->insert(4);
    A->swapFirstLast(A);
    A->display();
    return 0;
}