#include<iostream>

using namespace std;

int main()
{
	int n, t, c = 0;
	int sum;
	cin >> n;
	sum = n * 5;
	for (int i = 0; i != n; ++i)
	{
		cin >> t;
		if (t > c)
			sum += (t - c) * 6;
		if (t < c)
			sum += (c - t) * 4;
		c = t;
	}
	cout << sum;
	return 0;
}