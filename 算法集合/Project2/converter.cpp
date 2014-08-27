#include<iostream>
using namespace std;

int main()
{
	int num;
	int n=0;
	while (cin >> num)
	{
		cout << num;
		++n;
		if (n == 784)
		{
			n = 0;
			cout << endl;
		}
		else
			cout << " ";
	}
	return 0;
}