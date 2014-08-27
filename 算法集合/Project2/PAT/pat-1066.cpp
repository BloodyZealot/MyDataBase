#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

struct node
{
	int val;
	node* left;
	node* right;
	int height;
};

inline int height(node*pos)
{
	int l = pos->left ? pos->left->height : -1;
	int r = pos->right ? pos->right->height : -1;
	return max(l, r) + 1;
}
inline bool balance(node* pos)
{
	int l = pos->left ? pos->left->height : -1;
	int r = pos->right ? pos->right->height : -1;
	return abs(l - r) < 2.0;
}

node* rotate_ll(node* pos)
{
	node* temp = pos->left;
	pos->left = temp->right;
	temp->right = pos;
	pos->height = height(pos);
	temp->height = height(temp);
	return temp;
}

node* rotate_rr(node* pos)
{
	node* temp = pos->right;
	pos->right = temp->left;
	temp->left = pos;
	pos->height = height(pos);
	temp->height = height(temp);
	return temp;
}

node* rotate_rl(node* pos)
{
	pos->right = rotate_ll(pos->right);
	return rotate_rr(pos);
}

node* rotate_lr(node* pos)
{
	pos->left = rotate_rr(pos->left);
	return rotate_ll(pos);
}

node* insert(node* pos, int data)
{
	if (pos == 0)
	{
		return new node{ data, 0, 0, 0 };
	}
	if (pos->val < data)
	{
		pos->left = insert(pos->left, data);
		if (!balance(pos))
		{
			if (pos->left->val < data)
				pos = rotate_ll(pos);
			else
				pos = rotate_lr(pos);
		}
	}
	else
	{
		pos->right = insert(pos->right, data);
		if (!balance(pos))
		{
			if (pos->right->val < data)
				pos = rotate_rl(pos);
			else
				pos = rotate_rr(pos);
		}
	}
	pos->height = height(pos);
	return pos;
}

int main()
{
	int n, temp;
	node* root=0;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> temp;
		root = insert(root, temp);
	}
	cout << root->val;
	return 0;
}