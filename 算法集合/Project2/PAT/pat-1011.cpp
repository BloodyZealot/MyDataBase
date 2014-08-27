#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

double factor[3][3];
long long result;
double *p, *p2;

int main()
{
	for (int i = 0; i != 3; ++i)
		for (int j = 0; j != 3; ++j)
			cin >> factor[i][j];
	result = 1;
	for (int i = 0; i != 3; ++i)
	{
		p = factor[i];
		p2=max_element(p, p + 3);
		result *= int(*p2 * 10000);
		switch (p2-p)
		{
		case 0:
			cout << "W "; break;
		case 1:
			cout << "T "; break;
		case 2:
			cout << "L "; break;
		}
	}
	result /= 100000000;
	result = (result*65/100 - 10000) * 2;
	cout << result / 10000<<".";
	if (result % 100 / 10 > 4)
		cout << result % 10000 / 100 + 1;
	else
		cout << result % 10000 / 100;
	return 0;
}