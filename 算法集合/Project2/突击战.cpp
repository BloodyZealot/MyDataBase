#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

struct mission
{
	int talktime;
	int dotime;
};

bool operator < (const mission& m1,const mission& m2)
{
	if (m1.dotime == m2.dotime)
		return m1.talktime > m2.talktime;
	else
		return m1.dotime > m2.dotime;
}

int main()
{
	set<mission> missionset;
	mission temp;
	int n;
	int result1,result;
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		for (int i = 0; i != n; ++i)
		{
			cin >> temp.talktime >> temp.dotime;
			missionset.insert(temp);
		}
		set<mission>::iterator beg = missionset.begin(),end=missionset.end();
		result = beg->dotime + beg->talktime;
		result1 = beg->talktime;
		for (++beg; beg != end; ++beg)
		{
			result1 += beg->talktime;
			result = max(result, result1 + beg->dotime);
		}
		missionset.clear();
		cout << result<<endl;
	}
}