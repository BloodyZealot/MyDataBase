#include<iostream>

using namespace std;

int p[10][16];
int num[16];
int sum, tsum, n;
bool used[10];
bool sloved;

void print()
{
	sloved = true;
	for (int i = 1; i != n; ++i)
	{
		cout << num[i] << ' ';
	}
	cout << num[n];
}

void slove(int deep)
{
	for (int i = 0; i != n; ++i)
	{
		if (sloved)
			break;
		if (!used[i])
		{
			used[i] = true;
			num[deep] = i + 1;
			tsum += (num[deep] * p[n - 1][deep]);
			if (tsum >= sum || deep == n)
			{
				if (tsum == sum&&deep == n)
				{
					print();
				}
				tsum -= (num[deep] * p[n - 1][deep]);
				used[i] = false;
				return;
			}
			slove(deep + 1);
			tsum -= (num[deep] * p[n - 1][deep]);
			used[i] = false;
		}
	}
}

int main()
{
	cin >> n >> sum;
	p[0][1] = 1; p[0][0] = p[0][2] = 0;
	for (int i = 1; i != n; ++i)
	{
		for (int j = 1; j != i + 2; ++j)
			p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
		p[i][0] = p[i][i + 2] = 0;
	}
	for (int i = 0; i != n; ++i)
		used[i] = false;
	tsum = 0;
	sloved = false;
	slove(1);
	return 0;
}