#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n, m, k;
int result;

void findresult(int remains, int n, int k)
{
	if (k == 0 && n == 0)
		result++;
	else
	{
		if (remains > 0 && k > 0)
			findresult(remains - 1, n, k - 1);
		if (n > 0)
			findresult(remains + 1, n - 1, k);
	}
}

int main()
{
	cin >> m >> n >> k;
	result = 0;
	findresult(0, n, k);
	for (int i = 2; i <= n; ++i)
		result *= i;
	for (int i = 2; i <= k; ++i)
		result *= i;
	cout << result << endl;
	return 0;
}