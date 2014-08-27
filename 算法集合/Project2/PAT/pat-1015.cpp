#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

bool isprime(int num)
{
	if (num == 1)
		return false;
	if (num == 2 || num == 3)
		return true;
	int end = sqrt(num) + 1;
	for (int i = 2; i != end; ++i)
		if (num%i == 0)
			return false;
	return true;
}

int main()
{
	int num, d;
	vector<int> temp;
	while (cin >> num)
	{
		if (num < 0)
			break;
		cin >> d;
		if (isprime(num))
		{
			while (num != 0)
			{
				temp.push_back(num%d);
				num /= d;
			}
			for (int i = temp.size() - 1, j = 0; i != -1; --i, ++j)
			{
				num += temp[i] * pow(d, j);
			}
			if (isprime(num))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
		temp.clear();
	}
	return 0;
}