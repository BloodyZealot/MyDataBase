#include<iostream>

using namespace std;

int nextnum(int a)
{
	int temp = 0;
	while (a != 0)
	{
		temp += (a % 10)*(a % 10);
		a /= 10;
	}
	return temp;
}

int main()
{
	int n;
	int temp;
	int result = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		temp = i;
		while (temp != 89 && temp != 1)
			temp = nextnum(temp);
		if (temp == 89)
			++result;
	}
	cout << result;
	return 0;
}