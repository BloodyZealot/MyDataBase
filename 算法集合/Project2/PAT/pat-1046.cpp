#include<iostream>

using namespace std;

long long dist[100000];
long long temp,sum,half;

int main()
{
	int n;
	int starter, ender;
	cin >> n;
	dist[0] = 0;
	for (int i = 0; i != n; ++i)
	{
		cin >> temp;
		dist[i + 1] = dist[i] + temp;
	}
	sum = dist[n];
	half = sum / 2;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> starter >> ender;
		if (ender < starter)
			swap(starter, ender);
		temp = dist[ender - 1] - dist[starter - 1];
		if (temp > half)
			temp = sum - temp;
		cout << temp << endl;
	}
	return 0;
}