#include<iostream>
#include<algorithm>

using namespace std;

float Nami[1024], Ken[1024];

int main()
{
	int t;
	int n;
	int result1, result2;
	float *pn, *pk, *endn, *endk;
	cin >> t;
	for (int looper = 1; looper <= t; ++looper)
	{
		cin >> n;
		for (int i = 0; i != n; ++i)
			cin >> Nami[i];
		for (int i = 0; i != n; ++i)
			cin >> Ken[i];
		sort(Nami, Nami + n);
		sort(Ken, Ken + n);
		result1 = 0; result2 = 0;
		pn = Nami, pk = Ken, endn = Nami + n, endk = Ken + n;
		for (; pn != endn; ++pn)
		{
			if (*pn > *pk)
			{
				++result1;
				++pk;
			}
		}
		pn = Nami, pk = Ken;
		for (; pk != endk;++pk)
		{
			if (*pk > *pn)
			{
				++result2;
				++pn;
			}
		}
		result2 = n - result2;
		cout << "Case #" << looper << ": " << result1 <<" "<< result2 << endl;
	}
	return 0;
}