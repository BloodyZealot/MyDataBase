#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

bool isprime(long i)
{
	if (i == 2 || i == 3)
		return true;
	long end = sqrt(i) + 1;
	for (long a = 2; a != end; ++a)
		if (i%a == 0)
			return false;
	return true;
}

int main()
{
	map<int, int> result;
	map<int, int>::iterator beg, end;
	long long n;
	cin >> n;
	cout << n << '=';
	if (n != 1)
	{
		for (int i = 2; n != 1; ++i)
		{
			if (isprime(i) && n%i == 0)
			{
				while (n%i == 0)
				{
					result[i]++;
					n /= i;
				}
			}
		}
		beg = result.begin(), end = --result.end();
		for (; beg != end; ++beg)
		{
			if (beg->second != 1)
				cout << beg->first << '^' << beg->second << '*';
			else
				cout << beg->first << '*';
		}
		if (beg->second != 1)
			cout << beg->first << '^' << beg->second;
		else
			cout << beg->first;
	}
	else
		cout << 1;
	return 0;
}