#include<iostream>

using namespace std;

int main()
{
	int color,temp;
	size_t count=0;
	int n, m;
	cin >> n >> m;
	n *= m;	
	for (int i = 0; i != n; ++i)
	{
		scanf("%d",&temp);
		if (count == 0)
			color = temp;
		else
		{
			if (temp == color)
				++count;
			else
				--count;
		}
	}
	cout << color;
	return 0;
}