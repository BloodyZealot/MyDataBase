#include<iostream>
#include<string>

using namespace std;

string str[60], str1[60];
char ch[4] = { 'S', 'H', 'C', 'D' };
int arry[60];

int main()
{
	int n;
	int i, j, k;
	char ch1;
	for (k = 0; k<4; k++)
	{
		for (i = 1; i <= 13; i++)
		{
			if (i >= 10)
			{
				ch1 = '0' + (i % 10);
				str[k * 13 + i] = str[k * 13 + i] + ch[k] + '1' + ch1;
			}
			else
			{
				ch1 = '0' + i;
				str[k * 13 + i] = str[k * 13 + i] + ch[k] + ch1;
			}
		}
	}
	str[53] = "J1", str[54] = "J2";
	//for(i=1;i<=54;i++) cout<<str[i]<<endl;
	cin >> n;
	for (i = 1; i <= 54; i++)
	{
		cin >> k;
		arry[i] = k;
	}
	while (n--)
	{
		for (i = 1; i <= 54; i++)
		{
			str1[arry[i]] = str[i];
		}
		for (i = 1; i <= 54; i++)
		{
			str[i] = str1[i];
		}
	}
	for (i = 1; i <= 53; i++)
		cout << str1[i] << " ";
	cout << str1[i] << endl;
	return 0;
}