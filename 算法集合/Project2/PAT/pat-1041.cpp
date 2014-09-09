#include<iostream>
#include<map>

using namespace std;

int bets[100010];
map<int, int>judge;

int main()
{
	int n;
	int firstunique;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> bets[i];
		judge[bets[i]]++;
	}
	int index;
	for (index = 0; index != n; ++index)
	{
		if (judge[bets[index]] == 1)
		{
			cout << bets[index];
			return 0;
		}
	}
	cout << "None";
	return 0;
}