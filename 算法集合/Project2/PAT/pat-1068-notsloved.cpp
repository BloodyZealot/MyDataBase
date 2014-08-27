#include<iostream>
#include<algorithm>

using namespace std;

int stack[10010];
int num;
int coins[10010];
int remain;
int n;

bool slove(int deep, int starter)
{
	for (; starter != n&&remain >= coins[starter]; ++starter)
	{
		stack[deep] = coins[starter];
		remain -= coins[starter];
		if (remain == 0)
		{
			num = deep;
			return true;
		}
		if (slove(deep + 1, starter + 1))
			return true;
		remain += coins[starter];
	}
	return false;
}

int main()
{
	cin >> n >> remain;
	for (int i = 0; i != n; ++i)
		cin >> coins[i];
	sort(coins, coins + n);
	for (int i = n - 1; i != 0; --i)
		if (coins[i] < remain)
		{
			n = i + 1; break;
		}
	stack[0] = 0;
	if (slove(0, 0))
	{
		for (int i = 0; i != num; ++i)
			cout << stack[i] << ' ';
		cout << stack[num];
	}
	else
		cout << "No Solution";
	return 0;
}