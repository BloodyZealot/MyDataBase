#include<iostream>
#include<cstdlib>


using namespace std;

int main()
{
	wchar_t c;
	while (c=getwchar())
	{
		if (iswascii(c))
			if (iswalpha(c)||iswspace(c))
				putwchar(c);
	}
	return 0;
}