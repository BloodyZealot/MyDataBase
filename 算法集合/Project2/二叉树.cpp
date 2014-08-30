struct node
{
	int v;
	node* left;
	node* right;
};

void slove(const node * n, int &min, int &max)
{
	if (n->v < min)
		min = n->v;
	else
	{
		if (n->v > max)
			max = n->v;
	}
	if (n->left)
		slove(n->left, min, max);
	if (n->right)
		slove(n->right, min, max);
	return;
}

int findminusmax(const node*& parent)
{
	int max, min;
	if (!parent)//max-min>=0
		return -1;
	max = min = parent->v;
	slove(parent, min, max);
	return max - min;
}