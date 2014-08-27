#include<iostream>
#include<deque>

using namespace std;

bool trees[110][110];
int n, t;
int f, cn, cna;
int temp;
int leaves, flag;
deque<int> current, child;

void slove()
{
	while (1)
	{
		leaves = 0;
		while (current.size())
		{
			temp = current.front();
			current.pop_front();
			flag = child.size();
			for (int i = 0; i != n; ++i)
			{
				if (trees[temp][i])
					child.push_back(i);
			}
			if (flag == child.size())
				leaves++;
		}
		cout << leaves;
		if (child.size())
		{
			cout << " ";
			current.swap(child);
		}
		else
			return;
	}
}

int main()
{
	cin >> n >> t;
	++n;
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != n; ++j)
			trees[i][j] = false;
	for (int i = 0; i != t; ++i)
	{
		cin >> f >> cn;
		for (int j = 0; j != cn; ++j)
		{
			cin >> cna;
			trees[f][cna] = true;
		}
	}
	current.push_back(1);
	slove();
	return 0;
}