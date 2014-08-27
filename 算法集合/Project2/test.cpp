#include<iostream>
#include<algorithm>

using namespace std;

long long wall[10000];
long long t, sum;
int n, result;

int main()
{
	cin.sync_with_stdio(false);
	while (cin >> n >> t){
		for (int i = 0; i != n; ++i)
			cin >> wall[i];
		result = n + 1;
		for (int i = 0, j = 0; i != n; ++i)
		{
			sum = wall[i];
			for (j = i + 1; sum <= t&&j != n; ++j)
			{
				sum += wall[j];
			}
			if (j != n)
				result = min(result, j - i);
		}
		cout << (result == n + 1 ? -1 : result) << endl;
	}
	return 0;
}