#include<iostream>
using namespace std;

class BT
{
	int data;
	BT * LC, * RC;
public:
	BT()
	{ LC = RC = NULL; }

	BT * create()
	{
		BT * node = new BT();
		int x; 
		cout<<"Data > ";
		cin>>x;
		if(x==-1) return NULL;
		cout<<"L("<<x<<") > "; node->LC = create();
		cout<<"R("<<x<<") > "; node->RC = create();
		return node;
	}

	void inorder(BT * root)
	{
		if(root == NULL)	return;
		inorder(root->LC);
		cout<<root->data<<" ";
		inorder(root->RC);
	}

	int depth(BT * root)
	{
		if(root == NULL) return 0;
		int left = depth(root->LC);
		int right = depth(root->RC);
		if(left > right)	return left+1;
		else				return right+1;
	}

	void printLevel(BT * root, int k)	//Level 1 = Root, Level n = leaves
	{
		if(root == NULL)	return;
		if(k == 1)
			cout<<root->data<<" ";
		else
		{
			printLevel(root->LC, k-1);
			printLevel(root->RC, k-1);
		}
	}

	void inorder(BT * root)
	{
		if(root == NULL) return;
		int D = depth(root);
		for(int i=1; i<=D; i++)
		{
			printLevel(root, i);
			cout<<endl;
		}
	}

};