#include<iostream>
#include<algorithm>

using namespace std;

struct coin
{
	int v, b;
};
bool operator<(const coin& c1, const coin& c2)
{
	return c1.v < c2.v;
}

coin coins[36];
int n, c;
int result = 0;

int main()
{
	cin >> n >> c;
	for (int i = 0; i != n; ++i)
	{
		cin >> coins[i].v >> coins[i].b;
	}
	sort(coins, coins + n);
	for (int j = n - 1; j != -1; --j)
	{
		if (coins[j].v >= c)
		{
			result += coins[j].b;
			--n;
		}
		else
			break;
	}
	for (int j = n - 1; j != -1; --j)
	{
		
	}
}