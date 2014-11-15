#include<iostream>
#include<algorithm>

using namespace std;

struct thing
{
	int start;
	int endt;
};

bool operator<(const thing& t1, const thing& t2)
{
	if (t1.start < t2.start)
		return true;
	else
	{
		if (t2.endt < t2.endt)
			return true;
		else
			return false;
	}
}

thing things[100];

int main()
{
	int n;
	int result, counter;
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		for (int i = 0; i != n; ++i)
			cin >> things[i].start >> things[i].endt;
		sort(things, things + n);
		result = 1; counter = things[0].endt;
		for (int i = 1; i != n; ++i)
		{
			if (things[i].start >= counter)
			{
				counter = things[i].endt;
				result++;
			}
			else
			{
				if (counter > things[i].endt)
					counter = things[i].endt;
			}
		}
		if (counter < things[n - 1].start)
			++result;
		cout << result << endl;
	}
	return 0;
}