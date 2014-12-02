#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

struct note
{
	int l, r;
};

note dot[50];
int T, cnt, k, ans, id;
int v[50], m[50][50];
char a[10][11];

bool judge(int l, int r)
{
	if (dot[r].l <= dot[l].l)
		return true;
	return false;
}

void DFS(int l, int deep, int len)
{
	if (deep > ans)
		ans = deep;
	for (int i = 0; i < cnt; ++i)
		if (!v[i])
		{
		if ((len + m[l][i] <= k) && judge(l, i))
		{
			v[i] = 1;
			DFS(i, deep + 1, len + m[l][i]);
			v[i] = 0;
		}
		}
}

int main()
{
	scanf("%d", &T);
	for (int C = 0; C < T; ++C)
	{
		ans = 0;
		cnt = 0;
		memset(v, 0, sizeof(v));
		scanf("%d", &k);
		for (int i = 0; i < 5; ++i)
			scanf("%s", &a[i]);
		for (int i = 0; i < 5; ++i)
		{
			int j;
			for (j = 0; j < 9; ++j)
				if (a[i][j] == 'L')
				{
				dot[cnt].l = i;
				dot[cnt++].r = j;
				id = cnt - 1;
				a[i][j] = '*';
				}
				else if (a[i][j] == 'K')
				{
					dot[cnt].l = i;
					dot[cnt++].r = j;
				}
		}
		for (int i = 0; i < cnt; ++i)
			for (int j = 0; j < cnt; ++j)
				m[i][j] = abs(dot[i].l - dot[j].l) + abs(dot[i].r - dot[j].r);
		v[id] = 1;
		DFS(id, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
