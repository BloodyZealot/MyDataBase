#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct Usercase
{
	short No;
	int Id;
	int Date;
	short Score;
};

inline bool operator <(const Usercase& u1, const Usercase& u2)
{
	if (u1.Score == u2.Score)
	{
		if (u1.Date == u2.Date)
			return u1.Id < u2.Id;
		else
			return u1.Date<u2.Date;
	}
	else
		return u1.Score>u2.Score;
}

int main()
{
	int n;
	int num, calnum;
	int year, month, day;
	Usercase *beg, *end;
	Usercase *Userarray=new Usercase[10240];
	short *output=new short[10240];
	cin >> n;
	for (int loop = 0; loop != n; ++loop)
	{
		cin >> num;
		calnum = 0;
		for (short i = 0; i != num; ++i)
		{
			scanf("%d %d/%d/%d %d",
				&Userarray[i].Id, &year, &month, &day, &Userarray[i].Score);
			if (Userarray[i].Score > 0)
				++calnum;
			Userarray[i].Date = year * 10000 + month * 100 + day;
			Userarray[i].No = i;
		}
		sort(Userarray, Userarray + num);
		beg = Userarray;
		end = Userarray + num;
		for (int l6 = calnum * 3 / 100; l6 != 0; --l6)
			output[beg++->No] = 6;
		for (int l5 = calnum * 7 / 100; l5 != 0; --l5)
			output[beg++->No] = 5;
		for (int l4 = calnum * 2 / 10; l4 != 0; --l4)
			output[beg++->No] = 4;
		for (int l3 = calnum * 3 / 10; l3 != 0; --l3)
			output[beg++->No] = 3;
		while (beg->Score > 0)
			output[beg++->No] = 2;
		while (beg != end)
			output[beg++->No] = 1;
		for (int i = 0; i != num; ++i)
			cout << "LV" << output[i] << endl;
	}
	return 0;
}