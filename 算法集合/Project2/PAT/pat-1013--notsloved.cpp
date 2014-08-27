#include<iostream>
#include<memory.h>

using namespace std;

int citys[1010][1010];
int group[1010];

int main()
{
	int n, m, k;
	int c1, c2;
	cin >> n >> m >> k;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			citys[i][j] = -1;
	for (int i = 0; i != m; ++i)
	{
		cin >> c1 >> c2;
		citys[c1][c2] = citys[c2][c1] = 1;
	}
	int groupnum;
	int l;
	for (int i = 0; i != k; ++i)
	{
		cin >> c1;
		groupnum = 0;
		memset(group, 0, sizeof(int)*(1005));
		for (int j = 1; j <= n; ++j)
		{
			if (c1 != j&&group[j] == 0)
			{
				for (l = 1; l <= n; ++l)
				{
					if (citys[j][l] == 1 && l != c1)
					{
						if (group[l] == 0)
							group[l] = group[j] = ++groupnum;
						else
							group[j] = group[l];
						break;
					}
				}
				if (l > n)
					group[j] = ++groupnum;
			}
		}
		cout << (groupnum > 0 ? groupnum - 1 : 0) << endl;
	}
	return 0;
}