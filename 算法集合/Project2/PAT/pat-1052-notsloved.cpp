#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

struct node
{
	int v;
	int next;
};
bool operator< (const node& n1, const node& n2)
{
	return n1.v < n2.v;
}

struct sortnode
{
	int v;
	int add;
};
bool operator< (const sortnode& n1, const sortnode& n2)
{
	return n1.v < n2.v;
}

sortnode slit[100010];
node list[100010];

int main()
{
	int n, starter;
	int add;
	cin >> n >> starter;
	for (int i = 0; i != 100010; ++i)
		list[i].next = -4;
	for (int i = 0; i != n; ++i)
	{
		cin >> add;
		cin >> list[add].v >> list[add].next;
	}
	if (starter == -1)
	{
		cout << "0 -1";
		return 0;
	}
	n = 0;
	if(list[starter].next != -4)
	{
		while (starter >= 0)
		{
			slit[n].add = starter;
			slit[n].v = list[starter].v;
			++n;
			starter = list[starter].next;
		}
		sort(slit, slit + n);
		cout << n-- <<' '<< slit[0].add<<endl;
		for (int i = 0; i != n; ++i)
		{
			cout << setw(5) << setfill('0') << slit[i].add << ' ' 
				<< slit[i].v << ' ' 
				<< setw(5) << setfill('0') << slit[i + 1].add << endl;
		}
		cout << setw(5) << setfill('0') << slit[n].add << ' '
			<< slit[n].v << " -1";
	}
	else
		cout << 0 << setw(5) << setfill('0') << starter;
	return 0;
}