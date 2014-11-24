#include<iostream>
#include<bitset>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>

using namespace std;

int D[1000][1000];
bool connect[1000][1000];
int Team[1000];
int n, l, s, e;
int ls, le, lv;

struct node
{
	int city;
	int lenth;
	int teamnum;
};

bool operator<(const node& p1, const node& p2)
{
	return p1.lenth > p2.lenth;
}

priority_queue<node> opend;
bool closed[1000];

bool findresult = false;
int minlen = 0;
int path, team;
node tnode, tnode2;

void slove()
{
	while (opend.size())
	{
		tnode = opend.top();
		opend.pop();
		if (findresult&&tnode.lenth > minlen)
			continue;
		if (tnode.city == e)
		{
			if (tnode.lenth < minlen || !findresult)
			{
				findresult = true;
				minlen = tnode.lenth; path = 1; team = tnode.teamnum;
			}
			else if (tnode.lenth == minlen)
			{
				++path;
				if (tnode.teamnum > team) team = tnode.teamnum;
			}
			continue;
		}
		closed[tnode.city] = true;
		for (int i = 0; i != n; ++i)
		{
			if (!closed[i] && connect[tnode.city][i])
			{
				tnode2.city = i;
				tnode2.lenth = tnode.lenth + D[tnode.city][i];
				tnode2.teamnum = tnode.teamnum + Team[i];
				opend.push(tnode2);
			}
		}
	}
}

int main()
{
	cin >> n >> l >> s >> e;
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != n; ++j)
			connect[i][j] = false;
	for (int i = 0; i != n; ++i)
		cin >> Team[i];
	memset(&closed, 0, sizeof(bool)*n);
	for (int i = 0; i != l; ++i)
	{
		cin >> ls >> le >> lv;
		D[ls][le] = D[le][ls] = lv;
		connect[ls][le] = connect[le][ls] = true;
	}
	tnode.city = s; tnode.lenth = 0; tnode.teamnum = Team[s];
	opend.push(tnode);
	slove();
	cout << path << ' ' << team;
	return 0;
}