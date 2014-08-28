#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int linked[10010];
int map[10010][10010];
int n, p1, p2;
int maxdeep, node;
int num;
int result[10010];

void slove()
{
	stack<pair<int, int> > stack;
	int temp, deep;
	maxdeep = 0;
	stack.push(make_pair(1, 0));
	while (stack.size())
	{
		temp = stack.top().first;
		deep = stack.top().second;
		stack.pop();
		if (deep > maxdeep)
		{
			maxdeep = deep;
			node = temp;
		}
		linked[temp] = -1;
		for (int size = map[temp][0]; size != 0; --size)
		{
			if (linked[map[temp][size]] != -1)
				stack.push(make_pair(map[temp][size], deep + 1));
		}
	}
	stack.push(make_pair(node, 0));
	result[0] = node;
	num = 1;
	for (int i = 1; i <= n; ++i)
		linked[i] = 0;
	while (stack.size())
	{
		temp = stack.top().first;
		deep = stack.top().second;
		stack.pop();
		if (deep == maxdeep)
			result[num++] = temp;
		else
		{
			if (deep > maxdeep)
			{
				maxdeep = deep;
				result[1] = temp;
				num = 2;
			}
		}
		linked[temp] = -1;
		for (int size = map[temp][0]; size != 0; --size)
		{
			if (linked[map[temp][size]] != -1)
				stack.push(make_pair(map[temp][size], deep + 1));
		}
	}
	sort(result, result + num);
	for (int i = 0; i != num; ++i)
		cout << result[i] << endl;
}

int main()
{
	cin >> n;
	for (int i = 0; i != n; ++i)
		map[i][0] = 0;
	for (int i = 1; i != n; ++i)
	{
		cin >> p1 >> p2;
		map[p1][++map[p1][0]] = p2;
		map[p2][++map[p2][0]] = p1;
	}
	int temp = 1;
	linked[1] = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (linked[i] == 0)
			linked[i] = ++temp;
		for (int j = 1, ender = map[i][0]; j <= ender; ++j)
			linked[map[i][j]] = linked[i];
	}
	if (temp != 1)
		cout << "Error: " << temp << " components";
	else
		slove();
	return 0;
}