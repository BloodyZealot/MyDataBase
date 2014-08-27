#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

struct node
{
	int v;
	node *left, *right;
};

node*tree;
int inorder[32], porder[32];
deque<node*> outs;

void rebuildtree(int is,int ie,int ps,int pe,node* &parent)
{
	parent = new node();
	parent->v = porder[pe];
	if (is == ie)
		return;
	int splitpos = is;
	for (; inorder[splitpos] != parent->v; ++splitpos);
	int leftsize = splitpos - is;
	int rightsize = ie - splitpos;
	if (leftsize)
		rebuildtree(is, is + leftsize - 1, ps, ps + leftsize - 1, parent->left);
	if (rightsize)
		rebuildtree(ie - rightsize + 1, ie, pe - rightsize, pe - 1, parent->right);
}

void printtree()
{
	while (outs.size())
	{
		if (outs.front())
		{
			cout << " " << outs.front()->v;
			outs.push_back(outs.front()->left);
			outs.push_back(outs.front()->right);
		}
		outs.pop_front();
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i != n; ++i)
		cin >> porder[i];
	for (int i = 0; i != n; ++i)
		cin >> inorder[i];
	rebuildtree(0,n-1,0,n-1,tree);
	cout << tree->v;
	outs.push_back(tree->left);
	outs.push_back(tree->right);
	printtree();
	return 0;
}