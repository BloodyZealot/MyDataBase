#include<iostream>
#include<sstream>
#include<string>

using namespace std;

stringstream  ss;

int main()
{
	int i1;
	string s;
	int e;
	char t;
	cin >> i1;
	if (i1 < 0)
	{
		cout << "-";
		i1 *= -1;
	}
	cin >> t;
	if (t == '.')
	{
		while (cin >> t)
		{
			if (t == 'E')
				break;
			s.push_back(t);
		}
	}
	cin >> e;
	if (e < 0)
	{
		cout << "0.";
		e = -e;
		for (int i = 1; i != e; ++i)
			cout << "0";
		cout << i1 << s;
	}
	else
	{
		if (e >= s.size())
		{
			cout << i1 << s;
			for (int i = e - s.size(); i != 0; --i)
				cout << "0";
		}
		else
		{
			cout << i1;
			for (int i = 0; i != e; ++i)
				cout << s[i];
			cout << ".";
			for (int i = e; i != s.size(); ++i)
				cout << s[i];
		}
	}
	return 0;
}