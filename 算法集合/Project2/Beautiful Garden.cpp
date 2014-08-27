#include<iostream>
#include<set>
#include<iterator>
#include<algorithm>

using namespace std;

long long dis;
long long pos[64];
set<long long> posset;
int sum, temp, result;

int main()
{
	int t, n;
	cin >> t;
	for (int looper = 1; looper <= t; ++looper)
	{
		result = 40;
		cin >> n;
		for (int i = 0; i != n; ++i)
		{
			cin >> pos[i];
			posset.insert(pos[i]);
		}
		sort(pos, pos + n);
		if (n > 2)
		{
			for (int i = 0; i != n - 1; ++i)
			{
				for (int p = i + 1; p != n; ++p)
				{
					dis = pos[p] - pos[i];
					sum = 0;
					for (int j = i - 1, k = 1; j >= 0; --j, ++k)
					{
						sum += posset.count(pos[i] - k*dis) ? 0 : 1;
					}
					for (int j = i + 1, k = 1; j < n; ++j, ++k)
					{
						sum += posset.count(pos[i] + k*dis) ? 0 : 1;
					}
					if (sum < result)
						result = sum;
				}
			}
		}
		else
			result = 0;
		posset.clear();
		cout << "Case #" << looper << ": " << result << endl;
	}
	return 0;
}
