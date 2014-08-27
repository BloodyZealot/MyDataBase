#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int *pn, *pm;
	int sum;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			return 0;
		pn = new int[n];
		pm = new int[m];
		for (int i = 0; i != n; ++i)
			cin >> pn[i];
		for (int i = 0; i != m; ++i)
			cin >> pm[i];
		sort(pn, pn + n);
		sort(pm, pm + m);
		sum = 0;
		int pi, j;
		if (m < n)
			cout << "Loowaint ter is doomed!" << endl;
		else{
		for (pi = 0; pi != n; ++pi)
		{
			for (j = 0; j != m; ++j)
			{
				if (pm[j] >= pn[pi])
				{
					sum += pm[j];
					pm[j] = 0;
					break;
				}
			}
			if (j == m)
			{
				cout << "Loowater is doomed!" << endl;
				break;
			}
		}
		if (pi == n)
			cout << sum << endl;
		}
		delete[] pn;
		delete[] pm;
	}
}