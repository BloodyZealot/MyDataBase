#include<iostream>
#include<map>
#include<set>
#include<string>

using namespace std;

map<string, set<int>>database;
set<int>::iterator begptr, endptr;

int main()
{
	int n, k;
	cin >> n >> k;
	string name;
	int courseno, coursenum;
	for (int i = 0; i != k; ++i)
	{
		cin >> courseno >> coursenum;
		for (int j = 0; j != coursenum; ++j)
		{
			cin >> name;
			database[name].insert(courseno);
		}
	}
	for (int i = 0; i != n; ++i)
	{
		cin >> name;
		cout << name << ' ' << database[name].size();
		begptr = database[name].begin(), endptr = database[name].end();
		for (; begptr != endptr; ++begptr)
			cout << ' ' << *begptr;
		cout << endl;
	}
	return 0;
}

