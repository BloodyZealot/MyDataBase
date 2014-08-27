#include<iostream>

using namespace std;

int arr[100010];

int main()
{
	int n;
	int result = 0;
	int temp,temp2;
	cin >> n;
	for (int i = 0; i != n; ++i)
		cin >> arr[i];
	if (arr[0] != 0)
	{
		temp = arr[0];
		arr[0] = -1;
		result++;
		while (arr[temp] != 0)
		{
			result++;
			temp2 = arr[temp];
			arr[temp]=-1;
			temp = temp2;
		}
		arr[temp] = -1;
	}
	for (int i = 1; i != n;++i)
	{
		if (arr[i] != -1&&arr[i]!=i)
		{
			temp = arr[i];
			arr[i] = -1;
			result+=2;
		}
		while (arr[temp] != -1)
		{
			result++;
			temp2 = arr[temp];
			arr[temp] = -1;
			temp = temp2;
		}
	}
	cout << result;
	return 0;
}