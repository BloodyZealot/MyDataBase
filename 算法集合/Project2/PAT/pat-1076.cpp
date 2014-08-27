#include<iostream>
#include<bitset>
#include<deque>

using namespace std;

int upward[1010][1010];
int deep;
int n;
int usernum, temp;
int testnum;

int pos;
int num;
int tempdeep;
bitset<1024> bits;
deque<pair<int,int>> que;
int result;

void slove()
{
	result = 0;
	for (;que.size();que.pop_front())
	{
		if (que.front().second == deep)
			break;
		pos= que.front().first;
		num = upward[pos][0];
		tempdeep = que.front().second+1;
		for (int i = 1; i <= num; ++i)
		{
			if (!bits[upward[pos][i]])
			{
				bits[upward[pos][i]] = true;
				++result;
				que.push_back(make_pair(upward[pos][i], tempdeep));
			}
		}
	}
	cout << result << endl;
}

int main()
{
	cin >> n>>deep;
	for (int i = 1; i <= n; ++i)
		upward[i][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> usernum;
		for (int j = 0; j != usernum; ++j)
		{
			cin >> temp;
			upward[temp][++upward[temp][0]] = i;
		}
	}
	cin >> testnum;
	for (int i = 0; i != testnum; ++i)
	{
		cin >> temp;
		bits = 0;
		bits[temp] = true;
		que.clear();
		que.push_back(make_pair(temp,0));
		slove();
	}
	return 0;
}