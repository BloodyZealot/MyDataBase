#include<iostream>
#include<stack>

using namespace std;


struct pos
{
	int x, y;
	int dep;
	pos() :x(0), y(0), dep(0){};
	pos(int x1, int y1, int dep1) :x(x1), y(y1), dep(dep1){}
};

int maps[25][25];
pos nowpos;
int w, h;
int x, y;
int dir;
int result;

void solve(pos nowpos)
{
	int cx, cy;
	if (nowpos.dep++ > 10)
		return;
	x = nowpos.x; y = nowpos.y;
	while (!maps[++x][y]);
	switch (maps[x][y])
	{
	case 3:
		result = nowpos.dep < result ? nowpos.dep : result;
		return;
	case 1:
		if (nowpos.x != x - 1)
		{
			cx = x; cy = y;
			maps[cx][cy] = 0;
			solve(pos( x - 1, y, nowpos.dep ));
			maps[cx][cy] = 1;
		}
	case -1:
		break;
	}
	x = nowpos.x; y = nowpos.y;
	while (!maps[--x][y]);
	switch (maps[x][y])
	{
	case 3:
		result = nowpos.dep < result ? nowpos.dep : result;
		return;
	case 1:
		if (nowpos.x != x + 1)
		{
			cx = x, cy = y;
			maps[cx][cy] = 0;
			solve(pos( x + 1, y, nowpos.dep ));
			maps[cx][cy] = 1;
		}
	case -1:
		break;
	}
	x = nowpos.x; y = nowpos.y;
	while (!maps[x][++y]);
	switch (maps[x][y])
	{
	case 3:
		result = nowpos.dep < result ? nowpos.dep : result;
		return;
	case 1:
		if (nowpos.y != y - 1)
		{
			cx = x; cy = y;
			maps[cx][cy] = 0;
			solve(pos( x, y - 1, nowpos.dep ));
			maps[cx][cy] = 1;
		}
	case -1:
		break;
	}
	x = nowpos.x; y = nowpos.y;
	while (!maps[x][--y]);
	switch (maps[x][y])
	{
	case 3:
		result = nowpos.dep < result ? nowpos.dep : result;
		return;
	case 1:
		if (nowpos.y != y + 1)
		{
			cx = x, cy = y;
			maps[cx][cy] = 0;
			solve(pos( x, y + 1, nowpos.dep ));
			maps[cx][cy] = 1;
		}
	case -1:
		break;
	}
}

int main()
{
	while (cin >> w >> h)
	{
		if (w == 0 && h == 0)
			return 0;
		for (int i = 1; i <= h; ++i)
		{
			maps[i][0] = maps[i][w + 1] = -1;
			for (int j = 1; j <= w; ++j)
			{
				cin >> maps[i][j];
				if (maps[i][j] == 2)
				{
					maps[i][j] = 0;
					nowpos.x = i; nowpos.y = j;
				}
			}
		}
		for (int j = 1; j <= w; ++j)
			maps[0][j] = maps[h + 1][j] = -1;
		nowpos.dep = 0;
		result = 11;
		solve(nowpos);
		cout << (result == 11 ? -1 : result) << endl;
	}
	return 0;
}