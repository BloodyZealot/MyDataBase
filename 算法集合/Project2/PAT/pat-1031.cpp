#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int size = s.size();
	int n2 = 3;
	for (int i = 3; i != size; ++i)
	{
		if ((size + 2 - i) % 2 == 0)
		{
			if ((size + 2 - i) / 2 <= i)
			{
				n2 = i; break;
			}
		}
	}
	int n1 = (size - n2) / 2;
	string space(n2 - 2, ' ');
	string::iterator beg = s.begin(), end = --s.end();
	for (int i = 0; i != n1; ++i)
		cout << *(beg++) << space << *(end--)<<endl;
	cout << string(beg, ++end);
	return 0;
}