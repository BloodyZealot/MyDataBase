#include<iostream>
#include<bitset>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

struct node
{
	int city;
	long long lenth;
	long long cost;
};
struct line
{
	int len;
	int cost;
};
struct site
{
	int prevcity;
	int len;
	int cost;
};

bool operator<(const node&n1, const node& n2)
{
	if (n1.lenth != n2.lenth)
		return n1.lenth > n2.lenth;
	else
		return n1.cost > n2.cost;
}

line maps[510][510];
bitset<510> closed(0);
priority_queue<node, deque<node>> opened;
node tnode, tnode2;
long long n, m, startp, endp;
long long t1, t2, t3, t4;
site sites[510];

void slove()
{
	while (opened.size())
	{
		tnode = opened.top();
		opened.pop();
		if (!closed[tnode.city]){
			closed[tnode.city] = true;
			for (int i = 0; i != n; ++i)
			{
				if (!closed[i]){
					if (maps[tnode.city][i].len != -1)
					{
						tnode2.city = i;
						tnode2.lenth = maps[tnode.city][i].len + tnode.lenth;
						tnode2.cost = tnode.cost + maps[tnode.city][i].cost;
						if (sites[i].len > tnode2.lenth ||
							sites[i].len == tnode2.lenth&&sites[i].cost > tnode2.cost ||
							sites[i].len == -1)
						{
							sites[i].len = tnode2.lenth;
							sites[i].cost = tnode2.cost;
							sites[i].prevcity = tnode.city;
							if (i != endp)
								opened.push(tnode2);
						}
					}
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m >> startp >> endp;
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != n; ++j)
			maps[i][j].len = -1;
	for (int i = 0; i != n; ++i)
		sites[i].len = -1;
	for (int i = 0; i != m; ++i)
	{
		cin >> t1 >> t2 >> t3 >> t4;
		maps[t1][t2].len = maps[t2][t1].len = t3;
		maps[t1][t2].cost = maps[t1][t2].cost = t4;
	}
	tnode.city = startp;
	tnode.lenth = 0;
	tnode.cost = 0;
	sites[startp].prevcity = -1;
	sites[startp].len = 0;
	sites[startp].cost = 0;
	opened.push(tnode);
	slove();
	t1 = endp;
	vector<int> guides(1, endp);
	while ((t1 = sites[t1].prevcity) != -1)
		guides.push_back(t1);
	for (int i = guides.size() - 1; i != -1; --i)
		cout << guides[i] << " ";
	cout << sites[endp].len << " " << sites[endp].cost;
	return 0;
}