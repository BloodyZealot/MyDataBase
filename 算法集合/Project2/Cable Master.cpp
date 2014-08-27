#include<iostream>
#include<iterator>
#include<algorithm>
#include<iomanip>
#include<cmath>

using namespace std;


int n, k;
int num;
double cables[10240];
double maxlen, minlen;
double temp;
typedef istream_iterator<double> iit;

int main()
{
	cin >> n >> k;
	copy(iit(cin), iit(), cables);
	maxlen = 1000*1000;
	minlen = 0;
	for (int i = 0; i != 100;++i)
	{
		temp = (maxlen + minlen) / 2;
		num = 0;
		for (int i = 0; i != n; ++i)
			num += cables[i] / temp;
		if (num < k)
			maxlen = temp;
		else
			minlen = temp;
	}
	cout << fixed << setprecision(2) << floor(temp*100)/100;
	return 0;
}
