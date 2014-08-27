#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<array>
using namespace std;

struct onec
{
	char c;
	int val;
};
 
char arr[10000][10000];
map<string,int> vs;
bool flag;

int main()
{
	int T, n, ave, num=0;
	vector<onec> v;
	onec temp;
	cin >> T;
	for (int outer = 1; outer <= T; ++outer)
	{
		cin >> n;
		ave = 0;
		cin.get();
		while (cin.get() != '\n')
		{
			cin.unget();
			cin >> temp.val >> temp.c;
			v.push_back(temp);
			ave += temp.val;
		}
		ave /= n;
		for (int i = 0, j = 0,k=0; i != n; ++j)
		{
			temp = v[j];
			num += temp.val;
			for (int l = 0;l != temp.val; ++l,++k)
				arr[k][i] = temp.c;
			if (num == ave)
			{
				num = 0;
				++i; k = 0;
			}
		}
		for (int i = 0; i != ave; ++i)
		{
			arr[i][n] = '\0';
			vs[string(arr[i])]++;
		}
		v.clear();
		while (cin.get() != '\n')
		{
			cin.unget();
			cin >> temp.val >> temp.c;
			v.push_back(temp);
		}
		for (int i = 0, j = 0, k = 0; i != n; ++j)
		{
			temp = v[j];
			num += temp.val;
			for (int l = 0; l != temp.val; ++l, ++k)
				arr[k][i] = temp.c;
			if (num == ave)
			{
				num = 0;
				++i; k = 0;
			}
		}
		v.clear();
		flag = true;
		for (int i = 0; i != ave; ++i)
		{
			arr[i][n] = '\0';
			if (--vs[string(arr[i])] < 0)
			{
				flag = false;
				cout << "Case " << outer << ": No" << endl;
				break;
			}
		}
		if (flag)
			cout << "Case " << outer << ": Yes" << endl;
		vs.clear();
	}
	return 0;
}