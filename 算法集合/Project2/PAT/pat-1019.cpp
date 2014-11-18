#include<iostream>
#include<vector>

using namespace std;

int main()
{
	long long n, b;
	vector<int> number;
	cin >> n >> b;
	while (n != 0)
	{
		number.push_back(n%b);
		n /= b;
	}
	if (number.size() <= 1)
	{
		cout << "Yes" << endl;
		if (number.size())
			cout << number[0];
		else
			cout << 0;
	}
	else
	{
		vector<int>::iterator beg = number.begin(), end = number.end()-1;
		for (; beg != end; ++beg, --end)
			if (*beg != *end)
				break;
		if (beg < end)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
		for (int i = number.size() - 1; i != 0; --i)
			cout << number[i] << ' ';
		cout << number[0];
	}
	return 0;
}