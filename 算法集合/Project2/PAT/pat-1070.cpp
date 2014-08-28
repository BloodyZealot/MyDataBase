#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

struct mooncake
{
	double ton;
	double val;
};

bool operator<(const mooncake& c1, const mooncake& c2)
{
	return c1.val*c2.ton > c2.val*c1.ton;
}

int n;
double remain;
double result;
mooncake ms[1010];

int main()
{
	cin >> n >> remain;
	for (int i = 0; i != n; ++i)
		cin >> ms[i].ton;
	for (int i = 0; i != n; ++i)
		cin >> ms[i].val;
	sort(ms, ms + n);
	result = 0.0;
	for (int i = 0; i != n&&remain != 0; ++i)
	{
		if (remain >= ms[i].ton)
		{
			remain -= ms[i].ton;
			result += ms[i].val;
		}
		else
		{
			result += remain*ms[i].val / ms[i].ton;
			break;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << result;
	return 0;
}