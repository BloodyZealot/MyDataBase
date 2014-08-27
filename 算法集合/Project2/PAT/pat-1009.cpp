#include<iostream>
#include<map>
#include<iomanip>

using namespace std;

int n1,n2;
int k[10];
double nk[10];
int tk;
double tnk;
map<int, double> result;
map<int, double>::reverse_iterator begp, endp;

int main()
{
	cin >> n1;
	for (int i = 0; i != n1; ++i)
	{
		cin >> k[i];
		cin >> nk[i];
	}
	cin >> n2;
	for (int i = 0; i != n2; ++i)
	{
		cin >> tk;
		cin >> tnk;
		for (int j = 0; j != n1; ++j)
		{
			result[tk + k[j]] += tnk*nk[j];
		}
	}
	begp = result.rbegin(), endp = result.rend();
	cout << setiosflags(ios::fixed) << setprecision(1); 
	int n = 0;
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
		return 0;
	}
}