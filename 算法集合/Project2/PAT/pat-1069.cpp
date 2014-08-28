#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

pair<int, int> sort1(int num)
{
	int digits[4];
	int result1=0, result2=0;
	for (int i = 0; i != 4; ++i)
	{
		digits[i] = num % 10;
		num /= 10;
	}
	sort(digits, digits + 4);
	for (int i = 0; i != 4; ++i)
	{
		result1 += digits[i] * pow(10, i);
		result2 *= 10;
		result2 += digits[i];
	}
	return make_pair(result1, result2);
}

int output(const pair<int, int>& p)
{
	cout << setw(4) << setfill('0') << p.first << " - "
		<< setw(4) << setfill('0') << p.second << " = "
		<< setw(4) << setfill('0') << p.first - p.second << endl;
	return p.first - p.second;
}

int main()
{
	int num;
	pair<int, int> temp;
	cin >> num;
	temp = sort1(num);
	if (temp.first == temp.second)
		output(temp);
	else{	
		num=output(temp);
		while (num != 6174)
		{
			temp = sort1(num);
			num=output(temp);
		}
	}
	return 0;
}
