#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	long long m, n, v, k;
	int result;
	for (int looper = 0; looper != t; ++looper){
		cin >> n >> m >> v >> k;
		result = 0;
		if (m >= n)
		{
			cout << result<<endl;
			continue;
		}
		else if ((m - v)*k <= m)
		{
			cout << -1<<endl;
			continue;
		}
		else while (m < n){
			m = (m - v)*k;
			++result;
		}
		cout << result<<endl;
	}
	return 0;
}