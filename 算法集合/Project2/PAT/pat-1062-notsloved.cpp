#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>

using namespace std;

struct p
{
	int id;
	int vg;
	int tg;
	int sum;
};

bool operator<(const p& p1, const p& p2)
{
	if (p1.sum == p2.sum)
	{
		if (p1.vg == p2.vg)
		{
			return p1.id < p2.id;
		}
		else
			return p1.vg > p2.vg;
	}
	else
		return p1.sum > p2.sum;
}

inline ostream& operator<<(ostream& out, const p& p)
{
	out << setw(8) << setfill('0') << p.id << ' '
		<< p.vg << ' ' << p.tg;
	return out;
}

p temp;
vector<p> sage, noble, fool, small;
vector<p> ::iterator begptr, endptr;
int n;
int minline, maxline;
int counting;

int main()
{
	cin >> n >> minline >> maxline;
	counting = 0;
	for (int i = 0; i != n; ++i)
	{
		cin >> temp.id >> temp.vg >> temp.tg;
		if (temp.tg < minline || temp.vg < minline)
			continue;
		else
		{
			temp.sum = temp.tg + temp.vg;
			if (temp.vg >= maxline)
			{
				if (temp.tg >= maxline)
					sage.push_back(temp);
				else
					noble.push_back(temp);
			}
			else
			{
				if (temp.tg < maxline&&temp.vg>temp.tg)
					fool.push_back(temp);
				else
					small.push_back(temp);
			}
			++counting;
		}
	}
	sort(sage.begin(), sage.end());
	sort(noble.begin(), noble.end());
	sort(fool.begin(), fool.end());
	sort(small.begin(), small.end());
	cout << counting << endl;
	begptr = sage.begin();
	endptr = sage.end();
	for (; begptr != endptr; ++begptr)
		cout << *begptr << endl;
	begptr = noble.begin();
	endptr = noble.end();
	for (; begptr != endptr; ++begptr)
		cout << *begptr << endl;
	begptr = fool.begin();
	endptr = fool.end();
	for (; begptr != endptr; ++begptr)
		cout << *begptr << endl;
	begptr = small.begin();
	endptr = small.end();
	for (; begptr != endptr; ++begptr)
		cout << *begptr << endl;
	return 0;
}