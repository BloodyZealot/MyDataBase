#include<iostream>
#include<vector>

using namespace std;

int main()
{
	char c;
	int sum = 0;
	vector<int> result;
	while (cin >> c)
		sum += c - '0';
	while (sum > 0){
		result.push_back(sum % 10);
		sum /= 10;
	}
	if (result.size() >= 1){
		for (int i = result.size() - 1; i != 0; --i)
		{
			switch (result[i])
			{
			case 0:
				cout << "zero "; break;
			case 1:
				cout << "one "; break;
			case 2:
				cout << "two "; break;
			case 3:
				cout << "three "; break;
			case 4:
				cout << "four "; break;
			case 5:
				cout << "five "; break;
			case 6:
				cout << "six "; break;
			case 7:
				cout << "seven "; break;
			case 8:
				cout << "eight "; break;
			case 9:
				cout << "nine "; break;
			}
		}
		switch (result[0])
		{
		case 0:
			cout << "zero"; break;
		case 1:
			cout << "one"; break;
		case 2:
			cout << "two"; break;
		case 3:
			cout << "three"; break;
		case 4:
			cout << "four"; break;
		case 5:
			cout << "five"; break;
		case 6:
			cout << "six"; break;
		case 7:
			cout << "seven"; break;
		case 8:
			cout << "eight"; break;
		case 9:
			cout << "nine"; break;
		}
	}
	else
		cout << "zero";
	return 0;
}