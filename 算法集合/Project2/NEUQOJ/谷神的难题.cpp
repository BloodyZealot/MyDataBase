#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<math.h>

using namespace std;

struct student
{
	int date;
	string name;
	int value;
};
struct node
{
	vector<student> v;
	int l, midl, midr, r;
};

bool operator<(const student& s1, const student& s2)
{
	if (s1.date == s2.date)
	{
		if (s1.value == s2.value)
			return s1.name < s2.name;
		else
			return s1.value > s2.value;
	}
	else
		return s1.date < s2.date;
}

bool compare(const student& s1, const student& s2)
{
	if (s1.value == s2.value)
	{
		if (s1.date == s2.date)
			return s1.name < s2.name;
		else
			return s1.date < s2.date;
	}
	else
		return s1.value > s2.value;
}

student stus[50010];
vector<node > tree;
vector<student> result;


void findresult(int ql, int qr, int node = 0)
{
	if (tree[node].l == ql&&tree[node].r == qr)
	{
		result.insert(result.end(),tree[node].v.begin(), tree[node].v.end());
		return;
	}
	else
	{
		if (tree[node].midl==-1)
			return;
		if (ql > tree[node].midl)
		{
			if (ql < tree[node].midr)
				findresult(tree[node].midr, qr, node * 2 + 2);
			else
				findresult(ql, qr, node * 2 + 2);
		}
		else if (qr < tree[node].midr)
		{
			if (qr>tree[node].midl)
				findresult(ql, tree[node].midl, node * 2 + 1);
			else
				findresult(ql, qr, node * 2 + 1);
		}
		else
		{
			findresult(ql, tree[node].midl, node * 2 + 1);
			findresult(tree[node].midr, qr, node * 2 + 2);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	tree.resize(2 * n - 1);
	for (int i = 0; i != n; ++i)
		cin >> stus[i].date >> stus[i].name >> stus[i].value;
	sort(stus, stus + n);
	int size = 2 * n - int(pow(2, int(log2(2 * n - 1))));
	int min = n - size;
	for (int i = (n - 1) + min, j = 0; j != size; ++i, ++j)
	{
		tree[i].v.resize(1);
		tree[i].v[0] = stus[j];
		tree[i].l = tree[i].r = stus[j].date;
		tree[i].midl = tree[i].midr = -1;
	}
	for (int i = (n - 1), j = size; j != n; ++i, ++j)
	{
		tree[i].v.resize(1);
		tree[i].v[0] = stus[j];
		tree[i].l = tree[i].r = stus[j].date;
		tree[i].midl = tree[i].midr = -1;
	}
	for (int i = n - 2; i != -1; --i)
	{
		tree[i].v.insert(tree[i].v.end(), tree[i * 2 + 1].v.begin(), tree[i * 2 + 1].v.end());
		tree[i].v.insert(tree[i].v.end(), tree[i * 2 + 2].v.begin(), tree[i * 2 + 2].v.end());
		tree[i].midl = tree[i * 2 + 1].r;
		tree[i].midr = tree[i * 2 + 2].l;
		tree[i].l = tree[i * 2 + 1].l;
		tree[i].r = tree[i * 2 + 2].r;
		sort(tree[i].v.begin(), tree[i].v.end(), compare);
		if (tree[i].v.size() > 11)
			tree[i].v.resize(11);
	}
	int r, ql, qr;
	cin >> r;
	for (int i = 0; i != r; ++i)
	{
		cin >> ql >> qr;
		result.clear();
		findresult(ql, qr);
		sort(result.begin(), result.end(), compare);
		if (result.size() >= 11)
			for (int i = 0; i != 11; ++i)
				cout << result[i].name << endl;
		else
		{
			for (size_t i = 0; i != result.size(); ++i)
				cout << result[i].name << endl;
			for (size_t i = result.size(); i != 11; ++i)
				cout << "XXX" << endl;
		}
		cout << endl;
	}
	return 0;
}