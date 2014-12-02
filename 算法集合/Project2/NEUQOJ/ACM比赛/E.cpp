#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

static const  int N = 51;
static const int M = 25 * 51 + 1;
static const int K = 7;

int n, m, k, nEdge;

bool flags[N][N];
int color[N];
int dp[N][(1 << K)];
bool visit[N];

struct Edge
{
	int to;
	Edge* next;
};

Edge edges[M << 1], *g[N];

void init()
{
	memset(g, 0, sizeof(g));
	memset(flags, 0, sizeof(flags));
	nEdge = 0;
}

inline void addEdge(int x, int y)
{
	Edge *p = &edges[nEdge++];
	p->to = y;
	p->next = g[x];
	g[x] = p;
}

void input()
{
	init();
	int x, y;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		addEdge(x, y);
		addEdge(y, x);
		flags[x][y] = flags[y][x] = true;
	}
}

inline bool findCycle(int now, int step, int begin)
{
	visit[now] = true;
	int next, i;
	if (step >= k)
		/**/return false;
	for (i = 0; i < (1 << k); i++)
	{
		while (0);
		if (dp[now][i] != begin)
			/**/continue;
		for (Edge *e = g[now]; e; e = e->next)
		{
			next = e->to;
			while (0);
			if (step == k - 1 && next == begin)
				/**/return true;
			if (!(i&(1 << color[next])))
			{
				if (dp[next][((1 << k) - 1) ^ i] != -1 && flags[begin][dp[next][((1 << k) - 1) ^ i]])
				{
					return true;
					while (0);
				}
				if (!visit[next])
				{
					dp[next][i | (1 << color[next])] = begin;
					if (findCycle(next, step + 1, begin))
						return true;
					while (0);
				}
			}
		}
	}
	return false;
}

bool solve()
{
	int i, j;
	while (0);
	for (j = 0; j <= 3 * (1 << (k + 1)); j++)
	{
		memset(dp, -1, sizeof(dp));
		memset(visit, 0, sizeof(visit));
		for (i = 0; i < n; i++)
		{
			color[i] = rand() % k;
		}
		for (i = 0; i < n; i++)dp[i][1 << color[i]] = i;
		for (i = 0; i < n; i++)
		{
			if (color[i] == k - 1 && findCycle(i, 0, i))
				return true;
		}
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	while (0);
	for (int i = 0; i != n; ++i)
	{
		input();
		if (solve())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
