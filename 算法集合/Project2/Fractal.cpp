#include<iostream>

using namespace std;

const int maxsize = 3 * 3 * 3 * 3 * 3 * 3;
char datas[maxsize][maxsize];

void initialize(int n)
{
	int len = pow(3, n - 1);
	for (int i = 0; i != len; ++i)
	for (int j = 0; j != len; ++j)
		datas[i][j] = ' ';
}

void create(int n, int x, int y)
{
	if (n == 1)
		datas[x][y] = 'X';
	else
	{
		int s = pow(3, n -2);
		create(n - 1, x, y);
		create(n - 1, x, y + s * 2);
		create(n - 1, x + s, y + s);
		create(n - 1, x + 2 * s, y);
		create(n - 1, x + 2 * s, y + s * 2);
	}
}

void print(int n)
{
	int len = pow(3, n - 1);
	for (int i = 0; i != len; ++i)
	{
		for (int j = 0; j != len; ++j)
			cout << datas[i][j];
		cout << endl;
	}
	cout << '-' << endl;
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == -1)
			return 0;
		initialize(n);
		create(n, 0, 0);
		print(n);
	}
	return 0;
}