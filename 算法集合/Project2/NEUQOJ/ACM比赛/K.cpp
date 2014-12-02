#include <iostream>
#include <cmath>

using namespace std;

static const double eps = 1e-10;

double h1, h2, d1, d2, a, b;
double A, B, C, abc;

int judge(double x)
{
	double y = b*(d2 - x)*(d2 - x);
	if (x < 0 || x > d2)  
		return 0;
	if (x > d1 && h1 - a*d1*d1 > h2 - eps)
		return 1;
	else if (y - b*(d1 - x)*(d1 - x) > h2 - eps)
		return 1;
	return 0;
}

int main()
{
	while (cin >> h1 >> h2 >> d1 >> d2 >> a >> b)
	{
		if (abs(h1 - a*d2*d2) < eps && h1 - a*d1*d1 > h2 - eps)
		{
			cout << "Yes" << endl;
			continue;
		}
		A = (b + a);
		B = -2 * b*d2;
		C = b*d2*d2 - h1;
		abc = B*B - 4 * A*C;
		if (abc < 0)
		{
			cout << "No" << endl;
			continue;
		}
		double x1 = ((-B) + sqrt(abc)) / (2 * A), x2 = ((-B - sqrt(abc))) / 2 / A;
		if (judge(x1) || judge(x2))
		{
			cout << "Yes" << endl;
			continue;
		}
		cout << "No" << endl;
	}
	return 0;
}
