#include<iostream>
#include<bitset>
#include<queue>
#include<algorithm>

using namespace std;

int D[510][510];
int Team[510];
int n,l,s,e;
int ls, le, lv;

int main()
{
	cin >> n >> l >> s >> e;
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != n; ++j)
			D[i][j] = 10000000;
	for (int i = 0; i != n; ++i)
		cin >> Team[i];
	for (int i = 0; i != l; ++i)
	{
		cin >> ls >> le >> lv;
		D[ls][le] = D[le][ls] = lv;
	}

}