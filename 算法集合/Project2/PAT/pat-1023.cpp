#include<iostream>
#include<vector>
#include<string>

using namespace std;

int times[10];
int comp[10];
vector<char> result;
string s;

int main()
{
	int count, temp;
	for (int i = 0; i != 10; ++i)
		times[i] = comp[i] = 0;
	count = 0;
	cin >> s;
	for (int i = s.size()-1; i != -1;--i)
	{
		times[s[i] - '0'] ++;
		temp = (s[i] - '0') * 2 + count;
		if (temp > 9)
		{
			count = temp / 10;
			temp %= 10;
		}
		else
			count = 0;
		comp[temp]++;
		result.push_back(temp + '0');
	}
	if (!count)
	{
		for (int i = 0; i != 10; ++i)
		{
			if (times[i] != comp[i])
			{
				cout << "No" << endl;
				goto end;
			}
		}
		cout << "Yes" << endl;
	}
	else
	{
		result.push_back(count + '0');
		cout << "No" << endl;
	}
end:
	for (int i = result.size() - 1; i != -1; --i)
		cout << result[i];
	return 0;
}