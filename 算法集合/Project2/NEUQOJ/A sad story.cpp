#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	int nums[6];
	int funv, fubery;
	cin >> t;
	for (int i = 0; i != t; ++i)
	{
		for (int j = 0; j != 6; ++j)
			cin >> nums[j];
		sort(nums, nums + 6);
		funv = nums[5] + nums[4];
		fubery = nums[3] + nums[2] + nums[1];
		if (funv == fubery)
			cout << "HeHe!" << endl;
		else
		{
			if (funv > fubery)
				cout << "What a sad story!" << endl;
			else
				cout << "It will be a sad story!" << endl;
		}
	}
	return 0;
}