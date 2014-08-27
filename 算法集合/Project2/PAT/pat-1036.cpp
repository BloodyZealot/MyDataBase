#include<iostream>
#include<set>
#include<string>

using namespace std;

struct stu
{
	int grade;
	string id;
	string name;
};

bool operator<(const stu& s1, const stu&s2)
{
	return s1.grade < s2.grade;
}

set<stu> male;
set<stu> female;

int main()
{
	stu temps;
	char gender;
	int n;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> temps.name >> gender >> temps.id >> temps.grade;
		switch (gender)
		{
			case 'M':
				male.insert(temps);
				break;
			case 'F':
				female.insert(temps);
				break;
		}
	}
	if (female.size())
		cout << female.rbegin()->name <<" "<< female.rbegin()->id<<endl;
	else
		cout << "Absent" << endl;
	if (male.size())
		cout << male.begin()->name << " " << male.begin()->id << endl;
	else
		cout << "Absent" << endl;
	if (female.size() && male.size())
		cout << female.rbegin()->grade - male.begin()->grade;
	else
		cout << "NA";
	return 0;
}