#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct stu
{
	string id;
	string name;
	int grade;
};

int fun;

bool fun1(const stu& s1, const stu& s2)
{
	return s1.id < s2.id;
}

bool fun2(const stu& s1, const stu& s2)
{
	if (s1.name == s2.name)
		return s1.id < s2.id;
	else
		return s1.name < s2.name;
}

bool fun3(const stu& s1, const stu& s2)
{
	if (s1.grade == s2.grade)
		return s1.id < s2.id;
	else
		return s1.grade < s2.grade;
}

vector<stu> stus;
vector<stu>::iterator begptr, endptr;
stu temp;

int main()
{
	int n;
	cin >> n >> fun;
	stus.reserve(n);
	for (int i = 0; i != n; ++i)
	{
		cin >> temp.id >> temp.name >> temp.grade;
		stus.push_back(temp);
	}
	switch (fun)
	{
		case 1:
			sort(stus.begin(), stus.end(), fun1); break;
		case 2:
			sort(stus.begin(), stus.end(), fun2); break;
		case 3:
			sort(stus.begin(), stus.end(), fun3); break;
	}

	begptr = stus.begin(), endptr = stus.end();
	for (; begptr != endptr; ++begptr)
		cout << begptr->id << " " << begptr->name << " " << begptr->grade << endl;
	return 0;
}