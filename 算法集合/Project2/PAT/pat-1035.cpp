#include<iostream>
#include<string>
#include<vector>

using namespace std;

string modify(string pass)
{
	for (int i = 0; i != pass.size(); ++i)
	{
		switch (pass[i])
		{
			case '1':
				pass[i] = '@'; break;
			case 'l':
				pass[i] = 'L'; break;
			case '0':
				pass[i] = '%'; break;
			case 'O':
				pass[i] = 'o'; break;
		}
	}
	return pass;
}

vector<pair<string, string> > result;

int main()
{
	int n;
	string teamname, teampass, after;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> teamname >> teampass;
		if ((after = modify(teampass)) != teampass)
			result.push_back(make_pair(teamname, after));
	}
	if (result.size())
	{
		cout << result.size() << endl;
		for (int i = 0; i != result.size(); ++i)
			cout << result[i].first << ' ' << result[i].second << endl;
	}
	else
	{
		if (n == 1)
			cout << "There is 1 account and no account is modified";
		else
			cout << "There are " << n << " accounts and no account is modified";
	}
	return 0;
}