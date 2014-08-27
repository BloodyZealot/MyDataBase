#include<iostream>

using namespace std;

int main()
{
	int t;
	int p, q;
	bool result;
	int i;
	cin >> t;
	for (int looper = 1; looper <= t; ++looper)
	{
		scanf("%d/%d", &p, &q);
		result = true;
		for (i = 0; p < q; ++i)
		{
			if (q % 2 == 0)
			{
				q /= 2;
			}
			else
			{
				result = false; break;
			}
		}
		cout << "Case #" << looper << ": ";
		if (result)
			cout << i << endl;
		else
			cout << "impossible" << endl;
	}
	return 0;
}