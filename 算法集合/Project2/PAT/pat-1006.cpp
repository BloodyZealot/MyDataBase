#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

struct tnode
{
	int h;
	int m;
	int s;
};

bool operator<(const tnode & t1, const tnode & t2)
{
	if (t1.h == t2.h)
	{
		if (t2.m == t2.m)
			return t1.s < t2.s;
		else
			return t1.m < t2.m;
	}
	else
		return t1.h < t2.h;
}
bool operator>(const tnode & t1, const tnode & t2)
{
	return !(t1 < t2);
}

istream& operator>>(istream& in, tnode& t)
{
	char tc;
	in >> t.h >> tc >> t.m >> tc >> t.s;
	return in;
}

int main()
{
	int n;
	string s, mins, maxs;
	tnode t, mint, maxt;
	mint.h = 99;
	maxt.h = maxt.m = maxt.s = 0;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> s;
		cin >> t;
		if (t < mint)
		{
			mint = t;
			mins = s;
		}
		cin >> t;
		if (t > maxt)
		{
			maxt = t;
			maxs = s;
		}
	}
	cout << mins << " " << maxs;
	return 0;
}