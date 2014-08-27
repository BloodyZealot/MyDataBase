#include<iostream>
#include<algorithm>

using namespace std;

struct rational
{
	long long up, down;
};

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long caldown(long long i1, long long i2)
{
	if (i1%i2 == 0)
		return i1;
	return i1*i2 / gcd(i1, i2);
}

void add(rational& r1, rational&r2)
{
	if (r1.down == r2.down)
		r1.up += r2.up;
	else
	{
		long long down;
		if (r1.down > r2.down)
			down = caldown(r1.down, r2.down);
		else
			down = caldown(r2.down, r1.down);
		r1.up = r1.up*(down / r1.down) + r2.up*(down / r2.down);
		r1.down = down;
	}
}

int main()
{
	long long n;
	cin >> n;
	rational sum, temp;
	char c;
	cin >> sum.up >> c >> sum.down;
	for (long long i = 1; i != n; ++i)
	{
		cin >> temp.up >> c >> temp.down;
		add(sum, temp);
	}
	long long gc = gcd(sum.up, sum.down);
	if (sum.up != 0)
	{
		if (sum.up > sum.down)
		{
			cout << sum.up / sum.down;
			if (sum.up%sum.down != 0)
				cout << " " << (sum.up%sum.down) / gc << "/" << sum.down / gc;
		}
		else
			cout << sum.up / gc << "/" << sum.down / gc;
	}
	else
		cout << 0;
	return 0;
}