#include<iostream>
#include<string>
#include<memory>
#include<cstring>

using namespace std;

int main()
{
	string s;
	int alpha[26];
	while (getline(cin,s))
	{
		memset(alpha, 0, sizeof(int)*26);
		for (int i = s.size() - 1; i != -1; --i)
		{
			if (isalpha(s[i]))
				alpha[s[i] - 'a']++;
		}
		for (int i = 0; i != 26; ++i)
		{
			cout << char('a' + i) <<':'<< alpha[i] << endl;
		}
		cout << endl;
	}
	return 0;
}