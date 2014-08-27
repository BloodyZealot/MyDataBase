#include<iostream>
#include<bitset>

using namespace std;

int nums[1010];
enum status
{
	ava,
	out,
	push
};

int main()
{
	int n, m, p;
	int looper,inlooper;
	int currentsize,maxava,top;
	int num;
	cin >> m >> n >> p;
	for (looper = 0; looper != p; ++looper)
	{
		maxava = 0, currentsize = m;
		top = -1;
		for (int i = 0; i != n; ++i)
			nums[i] = status::ava;
		for (inlooper = 0; inlooper != n; ++inlooper)
		{
			cin >> num;
			--num;
			if (num != maxava)
			{
				if (num == top)
				{
					nums[num] = status::out;
					if (++currentsize != m)
						for (int s = num-1; s != -1; --s)
							if (nums[s] == status::push)
							{
								top = s; break;
							}
				}
				else
				{
					if (nums[num] == status::push)
						break;
					nums[num] = status::out;
					for (int s = num - 1; s != top; --s)
					{
						if (nums[s] == status::ava)
						{
							nums[s] = status::push;
							if (--currentsize == 0)
								goto next;
						}
					}
					for (int s = num - 1; s != top; --s)
					{
						if (nums[s] == status::push)
						{
							top = s;
								break;
						}
					}
				}
			}
			else
			{
				if (currentsize == 0)
					break;
				nums[num] = status::out;
				for (int s = num+1; s != n; ++s)
					if (nums[s] == status::ava)
					{
					maxava = s; break;
					}
			}
		}
	next:
		if (inlooper++ != n)
		{
			for (; inlooper != n; ++inlooper)
				cin >> num;
			cout << "NO" << endl;
		}
		else
			cout << "YES" << endl;
	}
	return 0;
}