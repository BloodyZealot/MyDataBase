#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

char week[][4] = {
	"MON",
	"TUE",
	"WED",
	"THU",
	"FRI",
	"SAT",
	"SUN",
};

int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int size = s1.size() <= s2.size() ? s1.size() : s2.size();
	int i;
	for (i = 0; i != size; ++i)
	{
		if (s1[i] == s2[i])
			if (isupper(s1[i])&&s1[i]<'H')
			{
			cout << week[s1[i] - 'A'] << ' '; break;
			}
	}
	for (++i; i != size; ++i)
	{
		if (s1[i] == s2[i])
		{
			if (isdigit(s1[i]))
			{
				cout << setw(2) << setfill('0') << s1[i] - '0'; break;
			}
			else
				if (isupper(s1[i])&&s1[i]<'O')
				{
				cout << setw(2) << setfill('0') << s1[i] - 'A' + 10; break;
				}
		}
	}
	cout << ':';
	size = s3.size() <= s4.size() ? s3.size() : s4.size();
	for (i = 0; i != size; ++i)
		if (s3[i] == s4[i] && isalpha(s3[i]))
		{
		cout << setw(2) << setfill('0') << i << endl; break;
		}
	return 0;
}