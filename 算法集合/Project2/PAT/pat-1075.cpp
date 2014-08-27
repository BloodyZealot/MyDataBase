#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

struct user
{
	int id;
	bool show;
	int sum;
	int num;
	int sco[5];
};

bool operator<(const user& u1, const user& u2)
{
	if (u1.sum == u2.sum)
	{
		if (u1.num == u2.num)
			return u1.id < u2.id;
		else
			return u1.num > u2.num;
	}
	return u1.sum > u2.sum;
}

user users[10000];
int maxc[5];

int main()
{
	int n, k, m;
	int tid, tpr, tsc;
	cin >> n >> k >> m;
	for (int i = 0; i != k; ++i)
		cin >> maxc[i];
	for (int i = 0; i != n; ++i)
	{
		users[i].id = i+1;
		for (int j = 0; j != k; ++j)
			users[i].sco[j] = -1;
	}
	for (int i = 0; i != m; ++i)
	{
		cin >> tid >> tpr >> tsc;
		tid--;
		tpr--;
		if (users[tid].sco[tpr] < tsc)
		{
			users[tid].show = true;
			if (users[tid].sco[tpr] != -1)
				users[tid].sum += tsc - users[tid].sco[tpr];
			else
				users[tid].sum += tsc;
			users[tid].sco[tpr] = tsc;
			if (maxc[tpr] == tsc)
				users[tid].num++;
		}
		else
			if (users[tid].sco[tpr] == -1)
				users[tid].sco[tpr] = 0;
	}
	sort(users, users + n);
	int pos = 1;
	int truepos = 2;
	cout << "1 " << setw(5) << setfill('0') << users[0].id << ' ' << users[0].sum;
	for (int i = 0; i != k; ++i)
		if (users[0].sco[i] != -1)
			cout << ' ' << users[0].sco[i];
		else
			cout << " -";
	cout << endl;
	for (int i = 1; i != n; ++i	,truepos++)
	{
		if (users[i].show == 0)
			continue;
		if (users[i].sum < users[i - 1].sum)
			pos=truepos;
		cout << pos<<' ';
		cout << setw(5) << setfill('0') << users[i].id << ' ' << users[i].sum;
		for (int j = 0; j != k; ++j)
			if (users[i].sco[j] != -1)
				cout << ' ' << users[i].sco[j];
			else
				cout << " -";
		cout << endl;
	}
	return 0;
}