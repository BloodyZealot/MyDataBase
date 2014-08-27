#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	map<string, int> m;
	string t, t2;
	int n, size;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> t;
		t.erase(remove(t.begin(), t.end(), '-'), t.end());
		size = t.size();
		for (int i = 0; i != size; ++i)
			switch (t[i])
		{
			case 'A':case 'B':case 'C':
				t[i] = '2'; break;
			case 'D':case 'E':case 'F':
				t[i] = '3'; break;
			case 'G':case 'H':case 'I':
				t[i] = '4'; break;
			case 'J':case 'K':case 'L':
				t[i] = '5'; break;
			case 'M':case 'N':case 'O':
				t[i] = '6'; break;
			case 'P':case 'R':case 'S':
				t[i] = '7'; break;
			case 'T':case 'U':case 'V':
				t[i] = '8'; break;
			case'W':case'X':case 'Y':
				t[i] = '9'; break;
			default:break;
		}
		t.insert(3, 1, '-');
		++m[t];
	}
	bool flag = false;
	map<string, int>::iterator beg = m.begin(), end = m.end();
	if (beg == end)
		cout << endl;
	else
	{
		while (beg->second == 1 && beg != end)
			++beg;
		if (beg != end)
		{
			cout << beg->first << ' ' << beg->second;
			++beg;
			while (beg != end)
			{
				if (beg->second != 1)
				{
					flag = true;
					cout << endl << beg->first << ' ' << beg->second;
				}
				++beg;
			}
		}
		else
			cout << endl;
	}
	return 0;
}