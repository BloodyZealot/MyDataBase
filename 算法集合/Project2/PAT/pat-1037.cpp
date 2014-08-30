#include<iostream>
#include<algorithm>

using namespace std;

long long nc1[100000];
long long nc2[100000];
long long np1[100000];
long long np2[100000];

int cn1, cn2;
int pn1, pn2;
int n, temp;
long long result;

bool compare(const long long& v1,const long long& v2)
{
	return v1 > v2;
}

int main()
{
	cin >> n;
	cn1 = cn2 = 0;
	for (int i = 0; i != n; ++i)
	{
		cin >> temp;
		if (temp > 0)
			nc1[cn1++] = temp;
		else
			nc2[cn2++] = temp;
	}
	cin >> n;
	pn1 = pn2 = 0;
	for (int i = 0; i != n; ++i)
	{
		cin >> temp;
		if (temp > 0)
			np1[pn1++] = temp;
		else
			np2[pn2++] = temp;
	}
	sort(nc1, nc1 + cn1, compare);
	sort(nc2, nc2 + cn2);
	sort(np1, np1 + pn1, compare);
	sort(np2, np2 + pn2);
	result = 0;
	for (int i = 0; i != cn1&&i != pn1; ++i)
		result += nc1[i] * np1[i];
	for (int i = 0; i != cn2&&i != pn2; ++i)
		result += nc2[i] * np2[i];
	cout << result;
	return 0;
}