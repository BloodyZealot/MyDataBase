#include<iostream>
#include<deque>

using namespace std;

struct pos
{
	int x, y;
};

deque<pos> que;
char map[30][30];
int w, h;
pos temp;
int result;

void search()
{
	result = 0;
	while (!que.empty())
	{
		++result;
		temp = que.front();
		que.pop_front();
		if (map[temp.x][temp.y - 1] == '.')
		{
			map[temp.x][temp.y - 1] = '#';
			que.push_back(pos{ temp.x, temp.y - 1 });
		}
		if (map[temp.x][temp.y + 1] == '.')
		{
			map[temp.x][temp.y + 1] = '#';
			que.push_back(pos{ temp.x, temp.y + 1 });
		}
		if (map[temp.x - 1][temp.y] == '.')
		{
			map[temp.x - 1][temp.y] = '#';
			que.push_back(pos{ temp.x - 1, temp.y });
		}
		if (map[temp.x + 1][temp.y] == '.')
		{
			map[temp.x + 1][temp.y] = '#';
			que.push_back(pos{ temp.x + 1, temp.y });
		}
	}
}

int main()
{
	for (int i = 0; i != 30; ++i)
		map[0][i] = map[i][0] = '#';
	while (cin >> w >> h)
	{
		if (w == 0)
			return 0;
		for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= w; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == '@')
			{
				map[i][j] = '#';
				que.push_back(pos{ i, j });
			}
		}
		for (int i = 0; i != 30; ++i)
			map[h + 1][i] = map[i][w + 1] = '#';
		search();
		cout << result << endl;
	}
}