#include<iostream>

using namespace std;

int main()
{
	int result;
	for (int i = 1; i != 801; ++i)
	{
		result = i/5;
		switch ( (i-1) / 100)
		{
		case 3:result += 30; break;
		case 4:result += 60; break;
		case 5:result += 100; break;
		case 6:result += 130; break;
		case 7:result += 150; break;
		default:break;
		}
		if (result >= 226){
			cout << i<<"  "<<result << endl; break;
		}
	}
	return 0;
}