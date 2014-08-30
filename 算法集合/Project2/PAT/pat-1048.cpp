#include<iostream>

using namespace std;

int coins[5010];
int n, m;
int temp;

int main()
{
	cin >> n >> m;
	for (int i = 0; i != 510; ++i)
		coins[i] = 0;
	for (int i = 0; i != n; ++i)
	{
		cin >> temp;
		coins[temp]++;
	}
	if (m % 2 == 0)
		temp = m / 2;
	else
		temp = m / 2 + 1;
	for (int i = 0; i != temp; ++i)
	{
		if (coins[i]){
			if (coins[m - i])
			{
				cout << i << ' ' << m - i; 
				return 0;
			}
		}
	}
	if (m % 2 == 0 && coins[temp] == 2)
		cout << temp << ' ' << temp;
	else
		cout << "No Solution";
	return 0;
}