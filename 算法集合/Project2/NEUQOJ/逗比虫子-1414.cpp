#include<iostream>

using namespace std;

int main()
{
	int n, u, d,timer;
	while (1)
	{
		cin >> n >> u >> d;
		if (n == 0 && u == 0 && d == 0)
			return 0;
		timer = 0;
		while (n > 0)
		{
			if (timer % 2 == 0)
				n -= u;
			else
				n += d;
			++timer;
		}
		cout << timer << endl;
	}
	return 0;
}