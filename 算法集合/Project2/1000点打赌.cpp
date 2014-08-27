#include<iostream>

using namespace std;

int main()
{
	int sum = 0;
	for (int i = 1; i != 1001; ++i)
	{
		double temp = pow(i, 1.0 / 3.0);
		int a = temp;
		if (double(a) - temp > 0.0)
			--a;
		if (i% a== 0)
			sum += 1;
	}
	cout << sum << endl;
	return 0;
}