#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct user
{
	string s;
	int pos;
	int v;
};

bool cmp(const user&u1, const user&u2)
{
	if (u1.v == u2.v)
		return u1.s < u2.s;
	else
		return u1.v > u2.v;
}

vector<user> ranklist;
user temp;
int location[110]; 
int locationcurr[110];
int locationprev[110];
int n, m;

int main()
{
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> m;
		for (int j = 0; j != m; ++j)
		{
			cin >> temp.s >> temp.v;
			temp.pos = i;
			ranklist.push_back(temp);
		}
	}
	for (int i = 0; i != n; ++i)
		location[i] = 1;
	sort(ranklist.begin(),ranklist.end(),cmp);
	n = ranklist.size();
	cout << n<<endl;
	int curr;
	for (int i = 0; i != n; ++i)
	{
		if (i != 0 && ranklist[i].v == ranklist[i - 1].v)
			cout << ranklist[i].s << ' ' << curr << ' ' << ranklist[i].pos + 1<<' ';
		else
		{
			cout << ranklist[i].s << ' ' << i + 1 << ' ' << ranklist[i].pos + 1 << ' ';
			curr = i + 1;
		}
		if (location[ranklist[i].pos] == 1)
		{
			cout << 1;
			locationcurr[ranklist[i].pos] = 1;
			locationprev[ranklist[i].pos] = ranklist[i].v;
		}
		else
		{
			if (ranklist[i].v == locationprev[ranklist[i].pos])
				cout << locationcurr[ranklist[i].pos];
			else
			{
				cout << location[ranklist[i].pos];
				locationcurr[ranklist[i].pos] = location[ranklist[i].pos];
				locationprev[ranklist[i].pos] = ranklist[i].v;
			}
		}
		++location[ranklist[i].pos];
		cout << endl;
	}
	return 0;
}