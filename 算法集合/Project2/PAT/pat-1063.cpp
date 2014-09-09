#include<iostream>
#include<iomanip>
#include<set>
using namespace std;

set<int> sets[60];
set<int>::iterator begptr, endptr, judge;
int main()
{
	int n, m;
	int s1, s2;
	int temp;
	cin >> n;
	n++;
	for (int i = 1; i != n; ++i)
	{
		cin >> m;
		for (int j = 0; j != m; ++j)
		{
			cin >> temp;
			sets[i].insert(temp);
		}
	}
	cin >> n;
	cout << setiosflags(ios::fixed) << setprecision(1);
	for (int i = 0; i != n; ++i)
	{
		cin >> s1 >> s2;
		{
			temp = 0;
			begptr = sets[s1].begin();
			endptr = sets[s1].end();
			judge = sets[s2].end();
			for (; begptr != endptr; ++begptr)
			{
				if (sets[s2].find(*begptr) != judge)
					temp++;
			}
		}

		cout << temp*100.0 / (sets[s1].size() + sets[s2].size() - temp) << "%" << endl;
	}
	return 0;
}