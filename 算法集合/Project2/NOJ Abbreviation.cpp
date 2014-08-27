#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	int n;
	string s;
	stringstream ss;
	cin >> n;
	getline(cin, s);
	for (int looper = 0; looper != n; ++looper)
	{
		getline(cin, s);
		for (int i = 0; i != s.size(); ++i)
			s[i] = tolower(s[i]);
		ss << s;
		while (ss >> s)
		{
			if (s.size() < 3 || s == "the" || s == "and" || s == "for")
				continue;
			else
				cout << char(toupper(s[0]));
		}
		cout << endl;
		ss.clear();
	}
	return 0;
}