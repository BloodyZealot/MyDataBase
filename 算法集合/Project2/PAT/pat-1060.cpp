#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	bool equal = false;
	string n1, n2;
	string::size_type sp1, sp2, s1, s2;
	int l1, l2;
	int i, i1, i2, e1, e2;

	cin >> n;
	cin >> n1 >> n2;
	e1 = n1.size(), e2 = n2.size();
	sp1 = n1.find('.');
	s1 = n1.find_first_not_of('0');
	if (sp1 != string::npos)
	{
		if (s1 == sp1)
		{
			s1 = n1.find_first_not_of('0', sp1+1);
			l1 = s1-sp1-1;
			l1 *= -1;
			if (s1 == string::npos)
				l1 = 0;
		}
		else
		{
			l1 = sp1 - s1;
		}
	}
	else
	{
		l1 = n1.size() - s1;
		if (s1 == string::npos)
			l1 = 0;
	}
	sp2 = n2.find('.');
	s2 = n2.find_first_not_of('0');
	if (sp2 != string::npos)
	{
		if (s2 == sp2)
		{
			s2 = n2.find_first_not_of('0', sp2+1);
			l2 = s2-sp2-1;
			l2 *= -1;
			if (s2 == string::npos)
				l2 = 0;
		}
		else
		{
			l2 = sp2 - s2;
		}
	}
	else
	{
		l2 = n2.size() - s2;
		if (s2 == string::npos)
			l2 = 0;
	}
	if (l1 == l2)
	{
		if (l1 != 0)
		{
			for (i = 0, i1 = s1, i2 = s2;
				i != n&&i1 != e1&&i2 != e2; ++i1, ++i2)
			{
				if (n1[i1] != n2[i2])break;
				if (++i == n)
				{
					equal = true; break;
				}
			}
			if (i1 == e1&&i2 == e2)
				equal = true;
		}
		else
			equal = true;
	}
	if (equal)
	{
		cout << "YES ";
		cout << "0.";
		for (i = 0; s1 < e1&&i != n; ++s1)
			if (n1[s1] != '.')
			{
			cout << n1[s1]; ++i;
			}
		for (; i != n; ++i)
			cout << 0;
		cout << "*10^" << l1;
	}
	else
	{
		cout << "NO ";
		cout << "0.";
		for (i = 0; s1 < e1&&i != n; ++s1)
			if (n1[s1] != '.')
			{
			cout << n1[s1]; ++i;
			}
		for (; i != n; ++i)
			cout << 0;
		cout << "*10^" << l1;
		cout << " 0.";
		for (i = 0; s2 < e2&&i != n; ++s2)
			if (n2[s2] != '.')
			{
			cout << n2[s2]; ++i;
			}
		for (; i != n; ++i)
			cout << 0;
		cout << "*10^" << l2;
	}
	return 0;
}