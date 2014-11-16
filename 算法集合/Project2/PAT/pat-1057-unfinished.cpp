#include<iostream>
#include<stack>
#include<set>
#include<string>

using namespace std;

int main()
{
	multiset<int> median;
	multiset<int>::iterator med, finder;
	stack<int> stack;
	int n, temp;
	string s;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> s;
		switch (s[1])
		{
			case 'u':
				cin >> temp;
				stack.push(temp);
				median.insert(temp);
				if (median.size() == 1)
				{
					med = median.begin();
				}
				else
				{

					if (median.size() % 2 != 0)
					{
						if (temp >= *med)
							++med;
					}
					else
					{
						if (temp <= *med)
							--med;
					}
				}
				break;
			case 'o':
				if (stack.size() == 0)
					cout << "Invalid" << endl;
				else
				{
					temp = stack.top();
					cout << temp << endl;
					stack.pop();
					if (temp == *med)
					{
						if (median.size() % 2 == 0)
							median.erase(med++);
						else
							median.erase(med--);
					}
					else
					{
						if (median.size() % 2 == 0)
						{
							if (temp < *med)
								++med;
						}
						else
						{
							if (temp > *med)
								--med;
						}
						median.erase(median.find(temp));
					}
				}
				break;
			case 'e':
				if (median.size() == 0)
					cout << "Invalid" << endl;
				else
					cout << *med << endl;
		}
	}
	return 0;
}