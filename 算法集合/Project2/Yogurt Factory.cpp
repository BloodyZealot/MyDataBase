#include<iostream>

using namespace std;

int cost[10010], need[10010];
int s, n;
long long result;

int main()
{
	cin >> n >> s;
	cin >> cost[0] >> need[0];
	for (int i = 1; i != n; ++i)
	{
		cin >> cost[i] >> need[i];
		if (cost[i] > cost[i - 1] + s)
			cost[i] = cost[i - 1] + s;
	}
	result = 0;
	for (int i = 0; i != n; ++i)
		result += cost[i] * need[i];
	cout << result;
	return 0;
}