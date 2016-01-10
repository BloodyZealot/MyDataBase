#include <iostream>
#include <algorithm>
#include <string>
#include<cstring>
#define five 5
static const int constSize = 50;
using namespace std;

struct node
{
	int x, y;
};

node nodes[constSize];
int temp, cnt, k, result, id;
int v[constSize], m[constSize][constSize];
char arr[10][11];

bool small(int a, int b)
{
	if (nodes[b].x <= nodes[a].x)
		return true;
	return false;
}

void slove(int x, int deep=0, int len=0)
{
	if (deep > result)
		result = deep;
	for (int i = 0; i != cnt; ++i)
	{
		if (!v[i])
			if ((len + m[x][i] <= k) && small(x, i))
			{
				v[i] = 1;
				slove(i, deep + 1, len + m[x][i]);
				v[i] = 0;
			}
	}
}

int main()
{
	cin >> temp;
	for (int C = 0; C != temp; ++C)
	{
		result = 0;
		cnt = 0;
		memset(v, 0, sizeof(v));
		cin >> k;
		for (int i = 0; i != five; ++i)
			scanf("%s", &arr[i]);
		for (int i = 0; i != five; ++i)
		{
			for (int j = 0; j != 9; ++j)
			{
				if (arr[i][j] == 'L')
				{
					nodes[cnt].x = i;
					nodes[cnt++].y = j;
					id = cnt - 1;
					arr[i][j] = '*';
				}
				else if (arr[i][j] == 'K')
				{
					nodes[cnt].x = i;
					nodes[cnt++].y = j;
				}
			}
		}
		for (int i = 0; i < cnt; ++i)
			for (int j = 0; j < cnt; ++j)
				m[i][j] = abs(nodes[i].x - nodes[j].x) + abs(nodes[i].y - nodes[j].y);
		v[id] = 1;
		slove(id);
		cout << result<<endl;
	}
	return 0;
}
