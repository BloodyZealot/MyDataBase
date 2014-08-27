#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int nums[1000];
deque<pair<int, int>  > require;
pair<int, int> current;
bool space = false;

void outputtree()
{
	while (require.size()){
		current = require.front();
		require.pop_front();
		int lenth = current.second - current.first;
		if (lenth == 1)
		{
			if (space)
				cout << " ";
			else
				space = true;
			cout << nums[current.first];
			continue;
		}
		if (lenth == 0)
			continue;
		int min = log(lenth + 1) / log(2);
		int remain = lenth - pow(2, min) + 1;
		if (space)
			cout << " ";
		else
			space = true;

		if (remain > pow(2, min - 1))
		{
			cout << nums[int(current.first + pow(2, min) - 1)];
			require.push_back(make_pair(current.first, current.first + pow(2, min) - 1));
			require.push_back(make_pair(current.second - remain + 1, current.second));
		}
		else
		{
			cout << nums[int(current.first + pow(2, min - 1) - 1 + remain)];
			require.push_back(make_pair(current.first, current.first + pow(2, min - 1) - 1 + remain));
			require.push_back(make_pair(current.second - pow(2, min - 1) + 1, current.second));
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i != n; ++i)
		cin >> nums[i];
	sort(nums, nums + n);
	require.push_back(make_pair(0, n));
	outputtree();
	return 0;
}