#include<string>
#include<iostream>

using namespace std;


int main()
{
	int n;
	cin >> n;
	string s1,s2, result;	
	getline(cin, s1);
	getline(cin, s1);
	getline(cin, s2);
	for (int e1 = s1.size() - 1, e2 = s2.size() - 1; e1 != -1 && e2 != -1; --e1, --e2)
	{
		if (s1[e1] == s2[e2])
			result.push_back(s1[e1]);
		else
			break;
	}
	n -= 2;
	for (int i = 0; i != n; ++i)
	{
		getline(cin, s1);
		for (int j = 0, k = s1.size() - 1; j != result.size() && k != -1; ++j, --k)
		{
			if (result[j] != s1[k])
			{
				result.erase(j, result.size() - j);
				break;
			}
		}
	}
	if (result.size())
		for (int i = result.size() - 1; i != -1; --i)
			cout << result[i];
	else
		cout << "nai";
	return 0;
}