#include<iostream>

using namespace std;

char nums[10][10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
char cals[][10] = { " Yi", " Wan", " Qian", " Bai", " Shi", "" };
char fu[] = { "Fu " };
bool ling;
bool space;
int main()
{
	long long n;
	int up, down;
	cin >> n;
	if (n < 0)
	{
		cout << fu;
		n *= -1;
	}
	ling = false;
	if (n / 100000000 > 0)
	{
		cout << nums[n / 100000000] << cals[0];
		ling = true;
		space = true;
	}
	n %= 100000000;
	up = n / 10000;
	down = n % 10000;
	if (up != 0)
	{
		for (int i = 1000, j = 2; i != 0 && up != 0; i /= 10, ++j)
		{
			if (up / i != 0)
			{
				if (space)
					cout << " ";
				cout << nums[up / i] << cals[j];
				ling = true;
				space = true;
				up %= i;
			}
			else
			{
				if (ling && (up != 0 || down != 0))
				{
					cout << " " << nums[0];
					ling = false;
				}
			}
		}
		cout << cals[1];
	}
	if (down != 0)
	{
		for (int i = 1000, j = 2; i != 0 && down != 0; i /= 10, ++j)
		{
			if (down / i != 0)
			{
				if (space)
					cout << " ";
				cout<< nums[down / i] << cals[j];
				space = true;
				ling = true;
				down %= i;
			}
			else
			{
				if (ling && down != 0)
				{
					cout << " " << nums[0];
					ling = false;
				}
			}
		}
	}
	return 0;
}