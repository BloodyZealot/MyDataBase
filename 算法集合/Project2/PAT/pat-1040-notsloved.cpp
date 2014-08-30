#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s;
int maxsize;
int size;

int slove(int p1, int p2)
{
	for (; p1 != -1 && p2 != size; --p1, ++p2)
		if (s[p1] != s[p2])break;
	return p2 - p1 - 1;
}

int main()
{
	getline(cin, s);
	size = s.size();
	int i;
	for (i = 1; i != size - 1; ++i)
	{
		if (s[i - 1] == s[i])
			maxsize = max(slove(i - 1, i), maxsize);
		if (s[i - 1] == s[i + 1])
			maxsize = max(slove(i - 1, i + 1), maxsize);
	}
	if (s[i - 1] == s[i])
		maxsize = max(slove(i - 1, i), maxsize);
	cout << maxsize;
	return 0;
}