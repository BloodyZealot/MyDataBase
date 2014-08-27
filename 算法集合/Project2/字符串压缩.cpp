#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct onec
{
	char c;
	int val;
};

int word[26];

int main1()
{
	int T, n, ave,num;
	int  tempn;
	char tempc;
	vector<onec> v1;
	onec temp;
	cin >> T;
	for (int outer = 1; outer <= T;++outer)
	{
		cin >> n;
		ave = 0;
		cin.get();
		while (cin.get() != '\n')
		{
			cin.unget();
			cin >> temp.val >> temp.c;
			v1.push_back(temp);
			ave += temp.val;
		}
		ave /= n;
		for (int j = 0; j != 26; ++j)
			word[j] = 0;
		for (int loop = 1,i = 0; loop <= n; ++loop)
		{
			for (int val = 0; val != ave; ++i)
			{
				temp = v1[i];
				word[temp.c-'a'] += temp.val;
				val += temp.val;
			}
			num = 0;
			while (num != ave)
			{
				cin >> tempn >> tempc;
				num += tempn;
				word[tempc-'a'] -= tempn;
			}
			for (int j = 0; j != 26;++j)
			if (word[j] != 0)
			{
				cout << "Case " << outer << ": No"<<endl;
				while (cin.get() != '\n');
				goto restart;
			}
		}
		cout << "Case " << outer << ": Yes" << endl;
restart:		v1.clear();
	}
	return 0;
}