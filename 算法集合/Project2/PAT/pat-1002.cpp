#include<iostream>
#include<iomanip>
#include<map>
using namespace std;

map<int, double> result;
map<int, double>::reverse_iterator begp, endp;

int n, k;
double v;

int main()
{
	for (int i = 0; i != 2; ++i)
	{
		cin >> n;
		for (int j = 0; j != n; ++j)
		{
			cin >> k >> v;
			result[k] += v;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1);
	begp = result.rbegin(), endp = result.rend();
	n = 0;
	for (; begp != endp; ++begp)
		if (begp->second != 0.0)
			++n;
	cout << n;
	if (n != 0){
		begp = result.rbegin(), endp = result.rend();
		for (; begp != endp; ++begp)
		{
			if (begp->second != 0.0)
			{
				cout << " ";
				cout << begp->first << " " << begp->second;
			}
		}
	}
	return 0;
}