#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

struct line
{
	int s, e;
};

bool operator<(const line& l1, const line& l2)
{
	if (l1.s != l2.s)
		return l1.s < l2.s;
	else
		return l1.e < l2.e;
}


line cows[25010];
list<line> selected;
typedef list<line>::iterator ptr;
int n;
int endt;
int result;
int ctime;

int main()
{
		scanf("%d %d", &n, &endt);
		for (int i = 0; i != n; ++i)
			scanf("%d %d", &cows[i].s, &cows[i].e);
		result = 0; ctime = 1;
		cows[n].s = 1100000;
		sort(cows, cows + n);
		result = 0;
		ptr p;
		for (int i = 0; i != n; ++i)
		{
			if (cows[i].s != cows[i + 1].s)
			if (result == 0 || p->e < cows[i].e)
			{
				selected.push_back(cows[i]);
				p = --selected.end();
				++result;
			}
		}
		if (selected.begin()->s != 1)
		{
			cout << -1;
			return 0;
		}
		selected.push_back(cows[n]);
		ctime = selected.begin()->e;
		ptr p2=selected.begin();
		p = p2; ++p;
		ptr p3 = p; ++p3;
		for (int i = 1,end=result; i != end; ++i)
		{
			if (p->s <= ctime + 1)
			{
				
				if (p2->e + 1 >= p3->s)
				{
					p = selected.erase(p);
					p2 = --p;
					p3 = ++++p;
					--p;
					--result;
				}
				else
				{
					ctime = p->e;
					++p, ++p2, ++p3;
				}
			}
			else
				break;
		}
		if (ctime != endt)
			cout << -1;
		else
			cout << result;
	return 0;
}