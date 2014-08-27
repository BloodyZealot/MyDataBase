#include<iostream>
#include<bitset>
#include<algorithm>

using namespace std;

unsigned long long a[4];
unsigned long long min1, min2, max2, max1;
unsigned long long input;
unsigned long long medium;
bitset<60> bits;
int t, n, k;

int main()
{
	cin >> t;
	for (int looper = 1; looper <= t; ++looper)
	{
		cin >> n >> k;
		medium = 1ULL << (k - 1);
		min1 = min2 = medium;
		max1 = max2 = medium - 1;
		for (int i = 0; i != n; ++i)
		{
			cin >> bits;
			input = bits.to_ulong();
			if (input < medium)
			{
				if (input < min2)
				if (input < min1)
				{
					min2 = min1; min1 = input;
				}
				else
					min2 = input;
			}
			else
			{
				if (input>max2)
				if (input > max1)
				{
					max2 = max1; max1 = input;
				}
				else
					max2 = input;
			}
		}
		a[0] = medium - min1;
		a[1] = medium - min2;
		a[2] = max1 + 1 - medium;
		a[3] = max2 + 1 - medium;
		sort(a, a + 4);
		cout <<"Case #"<<looper<<": "<< a[3] + a[2] - 1 << endl;
	}
	return 0;
}