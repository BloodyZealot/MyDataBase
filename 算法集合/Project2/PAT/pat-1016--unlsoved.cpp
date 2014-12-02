#include<iostream>
#include<iomanip>
#include<set>
#include<map>
#include<string>

using namespace std;

long long Charge[24];
long long onedaysum;

struct Time
{
	int d, h, m;
};
long long CalMinute(const Time& t1, const Time & t2)
{
	long long minute = 0;
	if (t1.d != t2.d)
		minute += (t2.d - t1.d) * 24 * 60;
	if (t1.h != t2.h)
		minute += (t2.h - t1.h) * 60;
	minute += (t2.m - t1.m);
	return minute;
}
long long CalCharge(const Time &  t1, const Time &  t2)
{
	long long result = 0;
	if (t1.d != t2.d)
		result += (t2.d - t1.d)*onedaysum;
	if (t1.h == t2.h)
		result += Charge[t1.h] * (t2.m - t1.m);
	else
	{
		result += (60 - t1.m)*Charge[t1.h];
		for (long long i = t1.h + 1; i != t2.h; ++i, i %= 24)
			result += 60 * Charge[i];
		result += t2.m*Charge[t2.h];
	}
	return result;
}
istream& operator>>(istream& in, Time & t)
{
	char c;
	in >> t.d >> c >> t.h >> c >> t.m;
	return in;
}
ostream& operator<<(ostream& out, const Time & t)
{
	char c = ':';
	out << setw(2) << setfill('0') << t.d << c
		<< setw(2) << setfill('0') << t.h << c
		<< setw(2) << setfill('0') << t.m;
	return out;
}

enum Pstatue
{
	online,
	offline
};
struct Precord
{
	Pstatue stat;
	Time time;
};
bool operator<(const Precord & p1, const Precord & p2)
{
	if (p1.time.d != p2.time.d)
		return p1.time.d < p2.time.d;
	else
	{
		if (p1.time.h != p2.time.h)
			return p1.time.h < p2.time.h;
		else
			return p1.time.m < p2.time.m;
	}
}

map<string, set<Precord>> PhoneBill;
bool paired;

int main()
{
	onedaysum = 0;
	for (long long i = 0; i != 24; ++i)
	{
		cin >> Charge[i];
		onedaysum += Charge[i] * 60;
	}
	long long n;
	cin >> n;
	Precord tempP;
	string name, temps;
	long long month = 0;
	char c;
	for (long long i = 0; i != n; ++i)
	{
		cin >> name >> month >> c >> tempP.time;
		cin >> temps;
		if (temps[1] == 'n')
			tempP.stat = online;
		else
			tempP.stat = offline;
		PhoneBill[name].insert(tempP);
	}
	map<string, set<Precord>>::iterator beg = PhoneBill.begin(), end = PhoneBill.end();
	set<Precord>::iterator sbeg, send, stemp;
	long long total, current;
	for (; beg != end; ++beg)
	{
		if (beg->second.size() < 2)
			continue;
		paired = false;
		sbeg = beg->second.begin(), send = beg->second.end();
		total = 0;
		for (++sbeg; sbeg != send; ++sbeg)
		{
			if (sbeg->stat == offline)
			{
				stemp = sbeg;
				--stemp;
				if (stemp->stat == online)
				{
					current = CalCharge(stemp->time, sbeg->time);
					total += current;
					if (!paired)
						cout << beg->first << ' ' << setw(2) << setfill('0') << month << endl;
					cout << stemp->time << ' ' << sbeg->time << ' ' << CalMinute(stemp->time, sbeg->time)
						<< " $" << setw(2) << setfill('0') << current / 100 << '.'
						<< setw(2) << setfill('0') << current % 100 << endl;
					paired = true;
				}
			}
		}
		if (paired)
			cout << "Total amount: $" << setw(2) << setfill('0') << total / 100 << '.'
			<< setw(2) << setfill('0') << total % 100 << endl;
	}
	return 0;
}