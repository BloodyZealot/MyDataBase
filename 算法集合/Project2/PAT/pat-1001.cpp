#include<iostream>
#include<string>

using namespace std;

int main()
{
	int a, b, t;
	cin >> a >> b;
	string s;
	int sum = a + b;
	if (sum < 0)
	{
		sum *= -1;
		cout << "-";
	}
	t = 0;
	if (sum != 0){
		while (sum > 0)
		{
			s += (sum % 10 + '0');
			sum /= 10;
			if (++t == 3 && sum != 0)
			{
				s += ',';
				t = 0;
			}
		}
	}
	else
		s = "0";
	for (int i = s.size() - 1; i != -1; --i)
	{
		cout << s[i];
	}
	return 0;
}