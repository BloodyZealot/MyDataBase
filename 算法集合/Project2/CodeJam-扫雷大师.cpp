#include<iostream>

using namespace std;

short area[5][5];

int main()
{
	int t;
	int x, y, num;
	int remain;
	cin >> t;
	for (int looper = 1; looper <= t; ++looper)
	{
		cin >> x >> y >> num;
		if (x > 1&&y>1)
		{
			remain = x * y - num;
			if (remain < 4)
			{
				cout << "Case #" << looper << ":\nImpossible" << endl;
				continue;
			}
			for (int i = 0; i != x;++i)
			for (int j = 0; j != y; ++j)
				area[i][j] = 0;
			area[0][0] = 2;
			area[1][0] = area[1][1] = area[0][1] = 0;
			remain -= 4;
			for (int i = 1;; ++i)
			{
				if (remain<4)
				if (remain == 2)
				{
					remain -= 2;
					area[i][0] = 0;area
				}
			}
		}
		else
		{
			if (x*y - num < 2)
			{
				cout << "Case #" << looper << ":\nImpossible" << endl;
				continue;
			}
		}
	}
	return 0;
}