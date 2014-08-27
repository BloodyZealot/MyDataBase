#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int num[16];
int n;
int pos,len;
int result;
int n1, n2;
string s;

int main()
{
	cin >> n;
	getline(cin, s);
	for (int looper = 0; looper != n; ++looper)
	{
		getline(cin, s);
		len = 0; pos = s.size();
		for (int i = 0; i != pos;++i)
		{
			if (s[i] != ' ')
				num[len++] = s[i] - '0';
		}
		pos = len / 2;
		n1 = n2 = 0;
		for (int i = 0; i != pos; ++i)
			n1 = n1 * 10 + num[i];
		for (int i = pos; i != len; ++i)
			n2 = n2 * 10 + num[i];
		result = abs(n2 - n1);
		while (next_permutation(num, num + len))
		{
			n1 = n2 = 0;
			for (int i = 0; i != pos; ++i)
				n1 = n1 * 10 + num[i];
			for (int i = pos; i != len; ++i)
				n2 = n2 * 10 + num[i];
			if(abs(n2-n1)<result)
				result=abs(n2-n1);
		}
		cout << result << endl;
	}
	return 0;
}