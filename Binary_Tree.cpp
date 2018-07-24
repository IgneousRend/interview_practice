#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class BT
{
    int data;
    BT * LC, * RC;
public:
    BT()
    {
        LC = RC = NULL;
    }

    BT * create()
    {
        BT * node = new BT();
        int x;
        cout<<"Data >> ";   cin>>x;
        if(x==0)    return NULL;
        node->data = x;

        cout<<"Left  ("<<x<<") : ";  node->LC = create();
        cout<<"Right ("<<x<<") : ";  node->RC = create();
        return node;
    }

    BT * create(vector<int> *V)
    {
        static unsigned long int i=0;
        BT * node = new BT();
        int x = V->at(i++);
        if(x==0)    return NULL;
        node->data = x;

        node->LC = create(V);
        node->RC = create(V);
    }

    void inorder(BT * root)
    {
        if(root == NULL)    return;
        inorder(root->LC);
        cout<<root->data<<" ";
        inorder(root->RC);
    }

    void printKDistantNodes(BT * root, int k)
    {
        if(root == NULL)    return;
        if(k==0)
            cout<<root->data<<" ";
        else
        {
            printKDistantNodes(root->LC, k - 1);
            printKDistantNodes(root->RC, k - 1);
        }
    }

    int leaves(BT * root)
    {
        if (root == NULL)   return 0;
        else if(root->LC == NULL && root->RC == NULL)   return 1;
        else return (leaves(root->LC) + leaves(root->RC));
    }

    bool path(BT * root, int x)
    {
        if (root == NULL) return false;
        if (root->data == x) return true;
        if (path(root->LC, x) || path(root->RC, x))
        {
            cout << root->data << " ";
            return true;
        }
        return false;
    }

    bool path(BT * root, int x, vector<int> * V)
    {
        if (root == NULL) return false;
        if (root->data == x) return true;
        if (path(root->LC, x, V) || path(root->RC, x, V))
        {
            V->push_back(root->data);
            cout << root->data << " ";
            return true;
        }
        return false;
    }

    int LCA(BT * root, int x, int y)
    {
        vector<int> V1, V2;
        path(root, x, &V1);
        path(root, y, &V2);
        for(int i=0; i<V1.size(); i++)
        {
            for(int j=0; j<V2.size(); j++)
                if(V1[i]==V2[j])
                    return V1[i];
        }
        return -1;
    }

    int depth(BT * root)
    {
        if(root==NULL) return 0;
        int left = depth(root->LC);
        int right = depth(root->RC);
        if(left > right)    return left+1;
        else return right+1;
    }

    int size(BT * root)
    {
        if(root == NULL)    return 0;
        if(root->LC == NULL && root->RC == NULL )   return 1;
        return size(root->LC)+size(root->RC)+1;
    }

    BT * searchNode(BT * p, int x)
    {
        if(p==NULL) return NULL;
        if(p->data==x)  return p;
        if(searchNode(p->RC,x)==NULL)
            return searchNode(p->LC,x);
        if(searchNode(p->LC,x)==NULL)
            return searchNode(p->RC,x);
    }

    void LevelOrder(BT * root)
    {
        int D = depth(root);
        for(int i=1;i<=D;i++)
        {
            printGivenLevel(root, i);
            cout<<endl;
        }

    }

    void printGivenLevel(BT * root, int level)
    {
        if(root==NULL)  return;
        if(level==1)    cout<<root->data<<" ";
        else if(level>1)
        {
            printGivenLevel(root->LC, level-1);
            printGivenLevel(root->RC, level-1);
        }
    }

    void inorderStack(BT * root)
    {
        BT * current = root;
        stack<BT *> S;
        bool done = 0;

        while (!done)
        {
            if(current !=  NULL)
            {
                S.push(current);
                current = current->LC;
            }
            else
            {
                if (!S.empty())
                {
                    current = S.top();
                    S.pop();
                    cout<<current->data<<" ";
                    current = current->RC;
                }
                else
                    done = 1;
            }
        }
    }

    bool ifSameTrees(BT * root1, BT * root2)
    {
        if(root1 == NULL && root2 == NULL)  return true;
        if(root1 != NULL && root2 != NULL)
        {
            return ( root1->data == root2->data
            && ifSameTrees(root1->LC,root2->LC)
            && ifSameTrees(root1->RC, root2->RC));
        }
        else
            return false;
    }

    int Max(BT * root)
    {
        static int max = !(1<<31);
        if(root == NULL)    return max;
        Max(root->LC);
        if(root->data > max )   max=root->data;
        Max(root->RC);
        return max;
    }

    int Min(BT * root)
    {
        static int min = 1<<31;
        if(root == NULL)    return min;
        Min(root->LC);
        if(root->data < min )   min=root->data;
        Min(root->RC);
        return min;
    }

    void MorrisTraversal(BT *root)
    {
        BT *current,*pre;
        if(root == NULL)
            return;
        current = root;
        while(current != NULL)
        {
            if(current->LC == NULL)
            {
                cout<<current->data<<" ";
                current = current->RC;
            }
            else
            {
                pre = current->LC;
                while(pre->RC != NULL && pre->RC != current)
                    pre = pre->RC;
                if(pre->RC == NULL)
                {
                    pre->RC = current;
                    current = current->LC;
                }
                else
                {
                    pre->RC = NULL;
                    cout<<current->data<<" ";
                    current = current->RC;
                }
            }
        }
    }

    void printSpiralLevel(BT * root, int i, bool a)
    {
        if (root == NULL)   return;
        if (i==1)           cout<<root->data<<" ";
        else if(i>1)
        {
            if(a)
            {
                printSpiralLevel(root->LC,i-1,a);
                printSpiralLevel(root->RC,i-1,a);
            }
            else
            {
                printSpiralLevel(root->RC,i-1,a);
                printSpiralLevel(root->LC,i-1,a);
            }
        }
    }

    void printSpiral(BT * root)
    {
        bool a = 0;
        for(int i=1; i<=depth(root); i++)
        {
                printSpiralLevel(root,i,a);
                a = !a;
        }
    }

    int greater(int a, int b)
    {
        return (a >= b)? a: b;
    }
    
    int diameter(BT * tree)
    {
       if (tree == NULL)
         return 0;
     
      int lheight = depth(tree->LC);
      int rheight = depth(tree->RC);
     
      int ldiameter = diameter(tree->LC);
      int rdiameter = diameter(tree->RC);
     
      return greater(lheight + rheight + 1, 
        greater(ldiameter, rdiameter));
    } 

    void doubleTree(BT * node)
    {
        BT * oldLeft;
        if(node==NULL)  return;
        doubleTree(node->LC);
        doubleTree(node->RC);
        oldLeft = node->LC;
        node->LC = new BT();
        node->LC->data = node->data;
        node->LC->LC = oldLeft;
    }

    bool isFoldableUtil(BT * A, BT *B)
    {
        if(A==NULL && B==NULL)
            return true;
        if(A==NULL||B==NULL)
            return false;

        return isFoldableUtil(A->LC,B->RC)
                && isFoldableUtil(A->RC,B->LC);
    }

    bool isFoldable(BT * root)
    {
        if(root==NULL) return true;
        else return isFoldableUtil(root->LC, root->RC);
    }


    

};

int main()
{
    BT * A = new BT();
    // vector<int> V4;
    // int arr[] = {5,2,1,0,0,3,0,0,12,9,0,0,21,19,0,0,25,0,0};
    // for(int i=0; i<(sizeof(arr)/sizeof(int)); i++)
        // V4.push_back(arr[i]);
    A = A->create();
    A->LevelOrder(A);
    return 0;
}