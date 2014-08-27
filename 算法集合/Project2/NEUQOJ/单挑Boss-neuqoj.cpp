#include<iostream>

using namespace std;

int main()
{
	long long h, a, b, k;
	while (cin >> h >> a >> b >> k)
	{
		if (h == 0 && a == 0 && b == 0 && k == 0)
			return 0;
		if (a > h)
		{
			cout << "Mission Succeed"<<endl;
			continue;
		}
		if (b - a >= 0)
			cout << "Try Again" << endl;
		else
		{
			if ( (a - b)  > (h - a) / (k-1))
				cout << "Mission Succeed" << endl;
			else
			{
				if (k*(a - b) > a)
					cout << "Mission Succeed" << endl;
				else
					cout << "Try Again" << endl;
			}
		}
	}
	return 0;
}