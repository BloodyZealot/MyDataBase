#include<iostream>

using namespace std;

int main()
{
	int t[4];
	int judge = 0;
	cin >> t[0];
	for (int i = 1; i != 4 && judge != -1; ++i)
	{
		cin >> t[i];
		if (t[i] > t[i - 1])
			judge = judge >= 0 ? 1 : -1;
		else if (t[i] < t[i - 1])
			judge = (judge == 0 || judge == -2) ? -2 : -1;
		else
			judge = (judge == 0 || judge == -3) ? -3 : -1;
	}
	switch (judge)
	{
		case 1:
			cout << "Fish Rising" << endl; break;
		case -2:
			cout << "Fish Diving" << endl; break;
		case -3:
			cout << "Fish At Constant Depth" << endl; break;
		default:
			cout << "No Fish" << endl; break;
	}
	return 0;
}