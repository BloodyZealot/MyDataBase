#include<iostream>
#include<cmath>

using namespace std;

bool table[20000];

int findprime(int in)
{
	int i;
	if (in == 1)
		return 2;
	if (in == 2 || in == 3)
		return in;
	while (1)
	{
		for (i = 2; i*i <= in; ++i)
			if (in%i == 0)
				goto next;
		return in;
	next:++in;
	}
}

int main()
{
	int max, n;
	int t, spos, pos;
	cin >> max >> n;
	max = findprime(max);
	for (int i = 0; i != n; ++i)
	{
		cin >> t;
		spos = pos = t%max;
		for (int j = 1; j != max; ++j)
		{
			if (table[pos] == false)
			{
				table[pos] = true;
				cout << pos;
				goto nextloop;
			}
			pos = (t+j*j)%max;
		}
		cout << '-';
	nextloop:
		if (i != n-1)
			cout << ' ';
	}
	return 0;
}