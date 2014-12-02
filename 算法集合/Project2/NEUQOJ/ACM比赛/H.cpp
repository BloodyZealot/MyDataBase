#include <iostream>
#include <algorithm>

using namespace std;

int arr[200000][30];
int v, n;
int w[30];

int main()
{
	cin >> v >> n;
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	for (int i = 0; i <= n; ++i)
		arr[0][i] = 0;
	for (int i = 0; i <= v; ++i)
		arr[i][0] = 0;
	for (int i = 1; i <= v; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i >= w[j])
				arr[i][j] = max(arr[i][j - 1], arr[i - w[j]][j - 1] + w[j]);
			else
				arr[i][j] = arr[i][j - 1];
		}
	}
	cout << v - arr[v][n];
	return 0;
}
