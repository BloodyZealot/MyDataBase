#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	int d, m;
	long long num, result;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> d >> m;
		num = result = pow(2, d - 1);
		num /= 2;
		while (1)
		{
			if (!(m % 2))
				result += num;
			if ((++m /= 2) == 1)
				break;
			num /= 2;
		}
		cout << result << endl;
	}
	return 0;
}