#include<iostream>

using namespace std;

int main()
{
	long long g1, g2;
	int s1, k1, s2, k2;
	char c;
	cin >> g1 >> c >> s1 >> c >> k1;
	cin >> g2 >> c >> s2 >> c >> k2;
	k1 += k2;	s1 += s2;	g1 += g2;
	s1 += k1 / 29;	k1 %= 29;
	g1 += s1 / 17;	s1 %= 17;
	cout << g1 << c << s1 << c << k1;
	return 0;
}