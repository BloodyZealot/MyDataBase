#include<iostream>
#include<set>

using namespace std;

int maps[7][7];
set<int> s;
int sum;

void slove(int x,int y,int deep)
{
	if (deep == 6)
	{
		s.insert(sum);
		return;
	}
	else
		sum *= 10;
	if (maps[x][y - 1] != -1)
	{
		sum += maps[x][y - 1];
		slove(x, y - 1, deep + 1);
		sum -= maps[x][y - 1];
	}
	if (maps[x][y + 1] != -1)
	{
		sum += maps[x][y + 1];
		slove(x, y + 1, deep + 1);
		sum -= maps[x][y + 1];
	}
	if (maps[x - 1][y] != -1)
	{
		sum += maps[x - 1][y];
		slove(x - 1, y, deep + 1);
		sum -= maps[x - 1][y];
	}
	if (maps[x + 1][y] != -1)
	{
		sum += maps[x + 1][y];
		slove(x + 1, y, deep + 1);
		sum -= maps[x + 1][y];
	}
	sum /= 10;
}

int main()
{
	for (int i = 1; i != 6;++i)
	for (int j = 1; j != 6; ++j)
		cin >> maps[i][j];
	for (int i = 0; i != 7; ++i)
		maps[i][0] = maps[i][6] = maps[0][i] = maps[6][i] = -1;
	for (int i = 1; i != 6;++i)
	for (int j = 1; j != 6; ++j)
	{
		sum = maps[i][j];
		slove(i, j, 1);
	}
	cout << s.size();
	return 0;
}