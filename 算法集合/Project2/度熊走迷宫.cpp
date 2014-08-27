#include<iostream>

using namespace std;

//enum dire{up,down,right};
//dire route[10000];
//int line;

bool empty[100][100];
int value[100][100];

int result;
int temp;

int m, n;
int pm, pn;

void search()
{
	temp += value[pm][pn];
	empty[pm][pn] = false;
	if (pm == 0 && pn == n)
	{
		if (result <temp)
			result = temp;
		empty[pm][pn] = true;
		temp -= value[pm][pn];
		return;
	}
	if (pm > 0){
		if(empty[--pm][pn])
			search();
		++pm;
	}
	if (pn < n){
		if (empty[pm][++pn])
			search();
		--pn;
	}
	if (pm < m)
	{
		if(empty[++pm][pn])
			search();
		--pm;
	}
	empty[pm][pn] = true;
	temp -= value[pm][pn];
	return;
}

int main()
{
	int t;
	cin >> t;
	for (int looper = 1; looper <= t; ++looper)
	{
		cin >> m >> n;
		for (int i = 0; i != m;++i)
		for (int j = 0; j != n; ++j)
		{
			cin >> value[i][j];
			empty[i][j] = true;
		}
		--m, --n;
		pm=pn=temp=result = 0;
		search();
		cout << "Case #" << looper << ":" << endl << result << endl;
	}
	return 0;
}