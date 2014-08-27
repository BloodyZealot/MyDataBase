#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct r
{
	double v;
	string id;
};

bool operator<(const r& r1, const r& r2)
{
	return r1.v > r2.v;
}
vector<r> crank, mrank, erank, vrank;

string id;
int cv, mv, ev;
int  av;

int c, m, e, a;

bool comp(r& t)
{
	return t.id == id;
}

int main()
{
	int n, m1;
	cin >> n >> m1;
	for (int i = 0; i != n; ++i)
	{
		cin >> id;
		cin >> cv >> mv >> ev;
		crank.push_back(r{ cv, id });
		mrank.push_back(r{ mv, id });
		erank.push_back(r{ ev, id });
		av = (cv + mv + ev);
		vrank.push_back(r{ av, id });
	}
	sort(crank.begin(), crank.end());
	sort(mrank.begin(), mrank.end());
	sort(vrank.begin(), vrank.end());
	sort(erank.begin(), erank.end());
	for (int i = 0; i != m1; ++i)
	{
		cin >> id;
		c = find_if(crank.begin(), crank.end(), comp) - crank.begin();
		m = find_if(mrank.begin(), mrank.end(), comp) - mrank.begin();
		a = find_if(vrank.begin(), vrank.end(), comp) - vrank.begin();
		e = find_if(erank.begin(), erank.end(), comp) - erank.begin();
		if ( e == n)
			cout << "N/A" << endl;
		else
		{
			if (a <= c&&a <= m&&a <= e)
				cout << a + 1 << " A" << endl;
			else if (c <= e&&c <= m)
				cout << c + 1 << " C" << endl;
			else if (m <= e)
				cout << m + 1 << " M" << endl;
			else
				cout << e + 1 << " E" << endl;
		}
	}
	return 0;
}