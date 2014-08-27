#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

struct stu
{
	string name;
	string id;
	int score;
};

bool operator<(const stu&s1, const stu&s2)
{
	return s1.score > s2.score;
}

vector<stu> stus;
vector<stu>::iterator begp, endp;
stu temps;

int main()
{
	stus.reserve(10000);
	int n;
	int min, max;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> temps.name >> temps.id >> temps.score;
		stus.push_back(temps);
	}
	sort(stus.begin(), stus.end());
	if(n!=0)
		cin >> min >> max;
	begp = stus.begin(), endp = stus.end();
	while (begp != endp)
	{
		if ((begp)->score <= max)
			break;
		else
			++begp;
	}
	if (begp != endp&&begp->score>=min)
	{
		while (begp != endp)
			if ((begp)->score >= min)
			{
				cout << begp->name << " " << begp->id << endl;
				++begp;
			}
			else
				break;
	}
	else
		cout << "NONE";
	return 0;
}