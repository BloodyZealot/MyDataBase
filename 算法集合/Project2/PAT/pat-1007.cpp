#include<iostream>

using namespace std;

int n;
int nums[11000];
int maxsum, starter, ender;
int tempsum, tstarter, tender;

int main()
{
	cin >> n;
	for (int i = 0; i != n; ++i)
		cin >> nums[i];
	if (nums[0] >= 0)
	{
		tstarter = starter = 0;
		tender = ender = 0;
		maxsum = tempsum = nums[0];
	}
	else
	{
		tstarter = tender = 1;
		starter = 0;
		ender = n - 1;
		maxsum = -1;
		tempsum = 0;
	}
	for (int i = 1; i != n; ++i)
	{
		if (tempsum + nums[i] >= 0)
		{
			tempsum += nums[i];
			tender = i;
			if (tempsum > maxsum)
			{
				maxsum = tempsum;
				starter = tstarter;
				ender = tender;
			}
		}
		else
		{
			tempsum = 0;
			tstarter = i + 1;
		}
	}
	if (maxsum == -1)
		cout << 0 << " " << nums[0] << " " << nums[ender];
	else
		cout << maxsum << " " << nums[starter] << " " << nums[ender];
	return 0;
}