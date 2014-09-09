#include<iostream>
#include<sstream>
#include<string>
using namespace std;

bool judge(string& s)
{
	int size = s.size();
	for (int i = 0, j = size - 1; i <= j; ++i, --j)
		if (s[i] != s[j])
			return false;
	return true;
}

string nextnum(string s)
{
	string result;
	int count = 0;
	int size = s.size();
	for (int i = 0, j = size - 1; i!=size; ++i, --j)
	{
		count = s[i] + s[j] - '0' * 2+count;
		result.insert(result.begin(),char(count%10+'0'));
		count /= 10;
	}
	if (count!=0)
		result.insert(result.begin(), char(count % 10 + '0'));
	return result;
}

int main()
{
	int i,n;
	string s;
	cin >> s >> n;
	for (i = 0; i != n; ++i)
	{
		if (judge(s))
		{
			cout << s << endl << i;
			return 0;
		}
		s = nextnum(s);
	}
	cout << s << endl << n;
	return 0;
}