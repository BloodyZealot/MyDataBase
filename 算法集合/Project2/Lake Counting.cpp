#include<iostream>
#include<iterator>
#include<string>
using namespace std;

char data[128][128];
int N, M;
int lakecount = 0;

void deploy(int pi, int pj)
{
	data[pi][pj] = '.';
	if (data[pi + 1][pj] == 'W')
	{
		deploy(pi + 1, pj);
	}
	if (data[pi + 1][pj + 1] == 'W')
	{
		deploy(pi + 1, pj + 1);
	}
	if (data[pi + 1][pj - 1] == 'W')
	{
		deploy(pi + 1, pj - 1);
	}
	if (data[pi][pj + 1] == 'W')
	{
		deploy(pi, pj + 1);
	}
	if (data[pi][pj - 1] == 'W')
	{
		deploy(pi, pj - 1);
	}
	if (data[pi - 1][pj] == 'W')
	{
		deploy(pi - 1, pj);
	}
	if (data[pi - 1][pj + 1] == 'W')
	{
		deploy(pi - 1, pj + 1);
	}
	if (data[pi - 1][pj - 1] == 'W')
	{
		deploy(pi - 1, pj - 1);
	}
	return;
}

inline void search()
{
	for (int i = 1; i <= N; ++i)
	for (int j = 1; j <= M; ++j)
	{
		if (data[i][j] == 'W')
		{
			lakecount++;
			deploy(i, j);
		}
	}
}


int main()
{
	cin >> N >> M;
	string temp;
	getline(cin, temp);
	for (int i = 1; i <= N; ++i)
	{
		getline(cin, temp);
		copy(temp.begin(), temp.end(), &data[i][1]);
		data[i][M + 1] = data[i][0] = '.';
	}
	for (int i = 0; i <= N + 1; ++i)
		data[0][i] = data[N + 1][i] = '.';
	search();
	cout << lakecount << endl;
	return 0;
}
