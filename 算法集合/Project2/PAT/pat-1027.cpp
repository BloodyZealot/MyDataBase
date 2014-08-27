#include<iostream>

using namespace  std;

int main()
{
	int r;
	cout << "#";
	for (int i = 0; i != 3; ++i)
	{
		cin >> r;
		if (r / 13 < 10)
			cout << r / 13;
		else
			cout << char(r / 13 - 10 + 'A');
		if (r % 13 < 10)
			cout << r % 13;
		else
			cout << char(r % 13 - 10 + 'A');
	}
	return 0;
}