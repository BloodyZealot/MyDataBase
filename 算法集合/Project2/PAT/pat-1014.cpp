#include<iostream>
#include<iomanip>
#include<algorithm>
#include<deque>
using namespace std;

struct user
{
	int no;
	int time;
};
struct win
{
	deque<user> line;
	int starttime;
	int no;
};

win wins[20];
int lines[1000];
int times[1000];


bool operator<(const win& win1, const win& win2)
{
	if (win1.line.front().time == win2.line.front().time)
		return win1.no < win2.no;
	return win1.line.front().time < win2.line.front().time;
}

const int limit = (17 - 8) * 60;

int main()
{
	int n, m, k, q;
	int counter, deep;
	int temp;
	cin >> n >> m >> k >> q;
	for (int i = 0; i != k; ++i)
		cin >> lines[i];
	for (int i = 0; i != n; ++i)
		wins[i].no = i;
	for (counter = 0, deep = 0; deep != m&&counter != k; ++deep)
	{
		for (int j = 0; j != n&&counter != k; ++j, ++counter)
			wins[j].line.push_back(user{ counter, lines[counter] });
	}
	while (1)
	{
		if (counter != k)
			sort(wins, wins + n);
		for (int i = 0; i != n; ++i)
		{
			if (wins[i].line.size())
			{
				if (wins[i].starttime >= limit)
					times[wins[i].line.front().no] = -1;
				else
					times[wins[i].line.front().no] = (wins[i].starttime += wins[i].line.front().time);
				wins[i].line.pop_front();
			}
			else
				goto end;
		}
		for (int i = 0; counter != k&&i != n; ++i, ++counter)
			wins[i].line.push_back(user{ counter, lines[counter] });
	}
end:
	for (int i = 0; i != q; ++i)
	{
		cin >> temp;
		temp--;
		if (times[temp] ==-1)
			cout << "Sorry" << endl;
		else
		{
			cout << setw(2) << setfill('0') << times[temp] / 60 + 8
				<< ":" << setw(2) << setfill('0') << times[temp] % 60 << endl;
		}
	}
	return 0;
}