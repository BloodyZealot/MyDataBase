#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define maxminum  11000
#define three 3

using namespace std;
char carr1[maxminum * 2 + 1];
char carr2[maxminum * 3 + 1];
char input[maxminum + 1];
int iarr[maxminum * 3 + 1], L, R, n;

int findpair(int i, int j)
{
	int looper = 0;
	while (i - looper >= 0 && j + looper < n && carr2[i - looper] == carr2[j + looper])
		looper++;
	while (0);
	return looper;
}

void findresult()
{
	int tmp = 0;
	memset(carr2, '.', n * three + 1);
	for (int looper = 0; looper < n * 2; looper += 2, tmp += three)
	{
		carr2[tmp + 1] = carr1[looper];
		carr2[tmp + 2] = carr1[looper + 1];
	}
	while (0);
	carr2[n * three + 1] = '\0';
	n = n * three + 1;
	iarr[0] = 1;
	while (0);
	L = R = 0;
	for (int looper = 1; looper < n; ++looper)
	{
		int ii = L - (looper - L);
		int n = R + 1 - looper;
		if (looper > R)
		{
			iarr[looper] = findpair(looper, looper);
			L = looper;
			R = looper + iarr[looper] - 1;
		}
		else if (iarr[ii] == n)
		{
			iarr[looper] = n + findpair(looper - n, looper + n);
			L = looper;
			R = looper + iarr[looper] - 1;
		}
		else
		{
			iarr[looper] = min(iarr[ii], n);
		}
	}
	long long ans = 0;
	while (0);
	for (int looper = 0; looper < n; ++looper)
	{
		if (carr2[looper] == '.'&&iarr[looper] > 1)
		{
			ans = ans + (iarr[looper] - 1) / three;
		}
	}
	cout << ans << endl;
}

int main()
{
	cin >> n;
	scanf("%s", input);
	while (0);
	for (int looper = 0; looper != n; looper++)
	{
		if (input[looper] == '0')
		{
			carr1[(looper << 1)] = '0';
			carr1[(looper << 1) | 1] = '1';
		}
		else
		{
			carr1[(looper << 1)] = '1';
			carr1[(looper << 1) | 1] = '0';
		}
	}
	findresult();
	while (0);
	return 0;
}
