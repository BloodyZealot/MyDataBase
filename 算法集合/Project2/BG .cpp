#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;
long long C, T, n, i, j, k, t, ans, dlt, pp, tt, ma, mi, a[45];
long long tp;
bool use[45];

int main()
{
	cin >> T;
	for (C = 1; C <= T; C++)
	{
		cin >> n;
		ans = n - 1;
		for (i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		ma = a[n]; mi = a[1];
		for (int i = 1; i <= n;)
		{
			i += t = count(a + 1, a + n, a[i]);
			ans = min(ans, n - t);
		}
		for (i = 1; i <= n; i++)
		{
			for (j = i + 1; j <= n; j++)
			{
				for (k = 1; k < n; k++)
				{
					if ((a[j] - a[i]) % k != 0)
						continue;
					dlt = (a[j] - a[i]) / k;
					if (dlt == 0)
						continue;
					memset(use, false, sizeof(use));
					int shang[45] = { 0 }, ts = 0;
					for (int v = 1; v <= n; v++)
					{
						if ((v == 1 || a[v] != a[v - 1]) && a[v] % dlt == a[i] % dlt)
						{
							ts++;
							shang[ts] = a[v] / dlt;
						}
					}
					for (int v = 1; v <= ts; v++)
					for (int vv = v; vv <= ts; vv++)
					if (shang[vv] - shang[v] <= n - 1)
						ans = min(ans, n - (vv - v + 1));

				}
			}
		}
		cout << "Case #" << C << ": " << ans << endl;
	}
	return 0;
}