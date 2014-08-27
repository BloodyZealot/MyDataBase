#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct pos
{
	int x, y;
	int line;
};

queue<pos> s;
int maps[410][410];
int searched[410][410];
int x, y, t;
int n;
pos tpos;
int result;

int main()
{
	cin >> n;
	for (int i = 0; i != 410; ++i)
	for (int j = 0; j != 410; ++j)
		maps[i][j] = 1001;
	for (int i = 0; i != n; ++i)
	{
		cin >> x >> y >> t;
		++x; ++y;
		if (maps[x][y] > t)
			maps[x][y] = t;
		if (maps[x - 1][y] > t)
			maps[x - 1][y] = t;
		if (maps[x + 1][y] > t)
			maps[x + 1][y] = t;
		if (maps[x][y - 1] > t)
			maps[x][y - 1] = t;
		if (maps[x][y + 1] > t)
			maps[x][y + 1] = t;
	}
	for (int i = 1; i != 400; ++i)
	{
		for (int j = 1; j != 400; ++j)
			searched[i][j] = 0;
		searched[0][i] = searched[i][0] = searched[i][400] = searched[400][i] = 1;
	}
	result = 1001;
	tpos.x = tpos.y = 1;
	tpos.line = 0;
	s.push(tpos);
	while (!s.empty())
	{
		tpos = s.front();	s.pop();
		if (maps[tpos.x][tpos.y] == 1001)
		{
			result = tpos.line; break;
		}
		else
		{
			++tpos.line;
			++tpos.y;
			if ((searched[tpos.x][tpos.y]++) == 0 && maps[tpos.x][tpos.y] > tpos.line)
				s.push(tpos);
			++tpos.x; --tpos.y;
			if ((searched[tpos.x][tpos.y]++) == 0 && maps[tpos.x][tpos.y] > tpos.line)
				s.push(tpos);
			--tpos.x; --tpos.y;
			if ((searched[tpos.x][tpos.y]++) == 0 && maps[tpos.x][tpos.y] > tpos.line)
				s.push(tpos);
			--tpos.x; ++tpos.y;
			if ((searched[tpos.x][tpos.y]++) == 0 && maps[tpos.x][tpos.y] > tpos.line)
				s.push(tpos);
		}
	}
	if (result == 1001)
		result = -1;
	cout << result;
	return 0;
}