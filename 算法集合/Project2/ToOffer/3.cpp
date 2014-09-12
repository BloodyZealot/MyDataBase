#include<iostream>
#include<vector>

using namespace std;

const int maxsize = 1010;
int arr[maxsize][maxsize];

int m, n;
int t;

bool FindNumber()
{
	size_t x = 0, y = n-1;
	while (y!=-1&&x!=m&&arr[x][y] != t)
	{
		if (arr[x][y] > t)
			--y;
		else
			++x;
	}
	if (x == m || y == -1)
		return false;
	else
		return true;
}

int main()
{
	while (cin >> m >> n)
	{
		cin >> t;
		for (int i = 0; i != m; ++i)
		{
			for (int j = 0; j != n; ++j)
				cin >> arr[i][j];
		}
		if (FindNumber())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}