#include<iostream>

using namespace std;

int n[6];
int result;
bool toend;

int main()
{
	while (1)
	{
		toend = true;
		for (int i = 0; i != 6; ++i)
		{
			cin >> n[i];
			if (n[i] != 0)
				toend = false;
		}
		if (toend)
			return 0;
		//6*6
		result = n[5];
		//5*5
		result += n[4];
		n[0] = (n[0] - n[4] * 11 > 0) ? (n[0] - n[4] * 11) : 0;
		//4*4
		result += n[3];
		n[1] = n[1] - n[3] * 5;
		if (n[1] < 0)
		{
			n[1] *= -4;
			if (n[0]>n[1])
				n[0] -= n[1];
			else
				n[0] = 0;
			n[1] = 0;
		}
		//3*3
		if (n[2] % 4 == 0)
		{
			result += n[2] / 4;
		}
		else
		{
			result += n[2] / 4+1;
			int n1 = (4-n[2] % 4) * 9;
			int n2 = 5 - (n[2] % 4 - 1) * 2;
			if (n[1] > n2)
			{
				n1 -= n2 * 4;
				n[1] -= n2;
			}
			else
			{
				n1 -= n[1] * 4;
				n[1] = 0;
			}
			n[0] = n[0] > n1 ? n[0] - n1 : 0;
		}
		//2*2
		if (n[1] % 9 == 0)
		{
			result += n[1] / 9;
		}
		else
		{
			result += n[1] / 9 + 1;
			int n1 = 36 - (n[1] % 9)*4;
			n[0] = n[0] > n1 ? n[0] - n1 : 0;
		}
		//1*1
		result += n[0] / 36 + (n[0] % 36 ? 1 : 0);
		cout << result << endl;
	}
	return 0;
}