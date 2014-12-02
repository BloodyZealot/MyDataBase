#include<iostream>

using namespace std;

int arr[200010];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i != n; ++i)
		cin >> arr[i];
	if (n > 1 && (arr[0] < arr[1] || arr[n - 1] < arr[n - 2]))
		cout << "YES";
	else
	{
		if (n > 2)
		{
			n -= 1;
			for (int i = 1; i != n - 1; ++i)
				if (arr[i - 1]>arr[i] && arr[i] < arr[i + 1])
				{
				cout << "YES";
				return 0;
				}
		}
		cout << "NO";
	}
	return 0;
}