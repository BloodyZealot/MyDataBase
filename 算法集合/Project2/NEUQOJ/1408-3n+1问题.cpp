#include<iostream>

using namespace std;

int main()
{
	int t, n;
	int timer;
	cin >> t;
	for (int i = 0; i != t; ++i)
	{
		cin >> n;
		for (timer = 0; n != 1; ++timer)
		{
			if (n % 2 == 0)n /= 2;
			else (n *= 3) += 1;
		}
		cout << timer << endl;
	}
	return 0;
}