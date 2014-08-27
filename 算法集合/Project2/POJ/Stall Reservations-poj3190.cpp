#include<algorithm>
#include<cstdio>
#include<map>

using namespace std;

struct cow
{
	int s, e, n;
};

bool operator<(const cow& c1, const cow& c2)
{
	return c1.s < c2.s;
}

int temp;
multimap<int, int> stall;
int select[60000];
cow cows[60000];
int snum;
int n;


int main()
{
	scanf("%d", &n);
	for (int i = 0; i != n; ++i)
	{
		cows[i].n = i;
		scanf("%d %d", &cows[i].s, &cows[i].e);
	}
	snum = 0;
	sort(cows, cows + n);
	for (int i = 0; i != n; ++i)
		select[i] = -1;
	stall.insert(make_pair(cows[0].e, 1));
	snum=select[cows[0].n] = 1;
	for (int i = 1; i != n; ++i)
	{
		if (stall.begin()->first < cows[i].s)
		{
			temp = stall.begin()->second;
			stall.erase(stall.begin());
			stall.insert(make_pair(cows[i].e, temp));
			select[cows[i].n] = temp;
		}
		else
		{
			stall.insert(make_pair(cows[i].e, ++snum));
			select[cows[i].n] = snum;
		}
	}
	printf("%d\n", snum);
	for (int i = 0; i != n; ++i)
		printf("%d\n", select[i]);
	return 0;
}