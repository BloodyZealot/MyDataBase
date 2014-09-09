#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

struct node
{
	string add;
	int v;
};
bool operator< (const node& n1, const node& n2)
{
	return n1.v < n2.v;
}

node list[100010];

int main()
{
	int n, starter;
	cin >> n >> starter;
	for (int i = 0; i != n; ++i)
		cin >> list[i].add >> list[i].v >> starter;
	sort(list, list + n);
	if (n != 0)
	{
		cout << n-- << ' ' << list[0].add << endl;
		for (int i = 0; i != n; ++i)
			cout << list[i].add << ' ' << list[i].v << ' ' << list[i + 1].add << endl;
		cout << list[n].add << ' ' << list[n].v << ' ' << -1;
	}
	else
		cout << "0 -1";
	return 0;
}