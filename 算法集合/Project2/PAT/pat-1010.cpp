#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	int num1=0, num2=0, flag=0, radix1=0,starter=2;
	string a, b;
	cin >> a >> b >> flag >> radix1;
	if (flag == 2)
		swap(a, b);
	for (int size = a.size()-1,i=0; size != -1; --size,++i)
	{
		if (isalpha(a[size]))
			num1 += pow(radix1, i)*(a[size] - 'a' + 10);
		else
			num1 += pow(radix1, i)*(a[size] - '0');
	}
	for (int i = 0; i != b.size(); ++i)
		if (isalpha(b[i]))
			starter = (b[i] - 'a' + 11) > starter ? (b[i] - 'a' + 11) : starter;
		else
			starter = (b[i] - '0'+1) > starter ? (b[i] - '0'+1) : starter;
	for (; starter != 37; ++starter)
	{
		for (int size = b.size()-1,i=0; size != -1; --size,++i)
		{
			if (isalpha(b[size]))
				num2 += pow(starter, i)*(b[size] - 'a' + 10);
			else
				num2 += pow(starter, i)*(b[size] - '0');
		}
		if (num1 == num2)
		{
			cout << starter;
			return 0;
		}
		else
			num2 = 0;
	}
	cout << "Impossible";
	return 0;
}