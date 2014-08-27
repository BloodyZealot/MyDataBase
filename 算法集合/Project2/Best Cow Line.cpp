#include<iostream>

using namespace std;

char str[2048], res[2048];
int n;


bool biger(char *a, char *b)
{
	while (*++a == *--b);
	return *a > *b;
}

int main()
{
	cin >> n;
	char *start, *end;
	for (int i = 0; i != n; ++i)
		cin >> str[i];
	start = str;
	end = str + n - 1;
	int pos = 0;
	while (start != end)
	{
		if (*start == *end)
		{
			if (biger(start,end))
				res[pos++] = *(end--);
			else
				res[pos++] = *(start++);
		}
		else
		{
			if (*start > *end)
				res[pos++] = *(end--);
			else
				res[pos++] = *(start++);
		}
	}
	res[pos] = *start;
	for (int i = 0; i != n;)
	{
		for (int j = 0; j != 80 && i != n; ++j, ++i)
			cout << res[i];
		cout << endl;
	}
	return 0;
}