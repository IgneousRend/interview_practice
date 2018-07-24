#include <bits/stdc++.h>

using namespace std;

class LL {
public:
    int value;
    LL *next;

    LL() {
        next = NULL;
    }

    LL *create(int x) {
        LL *node = new LL();
        node->value = x;
        return node;
    }

    void insert(LL *head, int x) {
        LL *node = head;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = new LL();
        node->next->value = x;
    }

    void insertAt(LL * head, int x, int y)
    {
        if(x==0)
        {
            LL * temp = new LL();
            temp->next = head;
            temp->value = y;
            return;
        }
        else
        {
            LL * previous = NULL, * current = head;
            for(int i=0; i<x; i++)
            {
                if(current == NULL) return;
                previous = current;
                current = current->next;
            }
            previous->next = new LL();
            previous->next->value = y;
            previous->next->next = current;
        }

    }

    static void display(LL * head) {
        LL *node = head;
        if (node == NULL) {
            cout << "Empty list" << endl;
            return;
        }
        do {
            cout << node->value << " ";
            node = node->next;
        } while (node != NULL);
    }

    int length(LL *head) {
        int i = 0;
        LL *node = head;
        while (node != NULL) {
            i++;
            node = node->next;
        }
        return i;
    }

    int length() {
        int i = 0;
        LL *node = this;
        while (node != NULL) {
            i++;
            node = node->next;
        }
        return i;
    }

    bool isLoop(LL *head) {
        LL *node1 = head;
        LL *node2 = head;
        while (node1 and node2 and node2->next) {
            node1 = node1->next;
            node2 = node2->next->next;
            if (node1 == node2) {
                return true;
            }
        }
        return false;
    }

    void HalfSplit(LL *head, LL *&left, LL *&right) {
        LL *n1 = head;
        LL *n2 = head->next;

        while (n2) {
            n2 = n2->next;
            if (n2) {
                n2 = n2->next;
                n1 = n1->next;
            }
        }

        left = head;
        right = n1->next;
        n1->next = NULL;

    }

    LL *sortedMerge(LL *left, LL *right) {
        LL *res;
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        if (left->value <= right->value) {
            res = left;
            res->next = sortedMerge(left->next, right);
        } else {
            res = right;
            res->next = sortedMerge(left, right->next);
        }
        return res;
    }

    void mergeSort(LL *&head) {
        LL *node = head;
        LL *leftHalf, *rightHalf;
        if (head == NULL || head->next == NULL)
            return;
        HalfSplit(node, leftHalf, rightHalf);
        mergeSort(leftHalf);
        mergeSort(rightHalf);
        head = sortedMerge(leftHalf, rightHalf);
    }

    void deleteByValue(LL *&head, int x) {
        LL *node = head;
        LL *prev = NULL;
        if (head->value == x) {
            prev = head;
            head = head->next;
            delete prev;
            return;
        }
        while (node) {
            if (node->value == x) {
                prev->next = node->next;
                delete node;
                return;
            }
            prev = node;
            node = node->next;
        }
    }

    void deleteDuplicates(LL *head) {
        unordered_set<int> set;
        LL *previous = NULL;
        LL *current = head;
        while (current) {
            if (set.find(current->value) != set.end()) {
                previous->next = current->next;
                delete current;
            } else {
                set.insert(current->value);
                previous = current;
            }
            current = previous->next;
        }
    }

    void reverseList(LL *&head) {
        if (head == NULL) return;
        reverseUtility(head, NULL, head);
    }

    void reverseUtility(LL *&head, LL *previous, LL *current) {
        if (current->next == NULL) {
            current->next = previous;
            head = current;
            return;
        }

        LL *temp = current->next;
        current->next = previous;
        reverseUtility(head, current, temp);
    }

    void swapNodes(LL * &head, int x, int y)
    {
        if(head == NULL or x == y)
            return;
        LL * prevX , * prevY, *currX, * currY;

        prevX = NULL;
        currX = head;
        while(currX != NULL)
        {
            if(currX->value == x)
                break;
            prevX = currX;
            currX = currX->next;
        }

        prevY = NULL;
        currY = head;
        while(currY != NULL)
        {
            if(currY->value == y)
                break;
            prevY = currY;
            currY = currY->next;
        }

        if(currX == NULL or currY == NULL)
            return;

        if(prevX == NULL)
            head = currY;
        else
            prevX->next = currY;

        if(prevY == NULL)
            head = currX;
        else
            prevY->next = currX;

        LL * temp = currX->next;
        currX->next = currY->next;
        currY->next = temp;
    }

    void deleteAlternate(LL * head)
    {
        LL * current, * next;
        current = head;
        while(current != NULL and current->next != NULL)
        {
            next = current->next;
            current->next = current->next->next;
            delete next;
            current = current->next;
        }
    }
};


int main() {
    LL *obj = new LL();
    obj = obj->create(4);
    obj->insert(obj, 3);
    obj->insert(obj, 1);
    obj->insert(obj, 5);
    obj->insert(obj, 2);
    obj->insertAt(obj, 1, 13);
    LL a;
    cout<<a.length();

    return 0;
}