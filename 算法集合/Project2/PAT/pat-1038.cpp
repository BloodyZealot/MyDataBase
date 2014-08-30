#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string segment[10000];

bool compare(const string& s1, const string& s2)
{
	return s1 + s2 < s2 + s1;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i != n; ++i)
		cin >> segment[i];
	sort(segment, segment + n,compare);
	string sum;
	for (int i = 0; i != n; ++i)
		sum += segment[i];
	int size = sum.size();
	int index = 0;
	for (; index != n; ++index)
		if (sum[index] != '0')
			break;
	if (index != n)
		cout << string(sum, index, size - index);
	else
		cout << 0;
	return 0;
}