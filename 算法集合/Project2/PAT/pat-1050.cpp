#include<cstdio>
#include<iostream>
#include<string>
#include<bitset>

using namespace std;

string s1;
string s2;
bitset<0x1FFFF> bits(0);

int main()
{
	getline(cin, s1);
	getline(cin, s2);
	int size = s2.size();
	for (int i = 0; i != size; ++i)
		bits[s2[i]] = true;
	size = s1.size();
	for (int i = 0; i != size; ++i)
	{
		if (!bits[s1[i]])
			printf("%c", s1[i]);
	}
	return 0;
}