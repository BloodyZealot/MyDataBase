#include <stdio.h>
#include <ctype.h>

int main()
{
	char c;
	while (c = getchar())
	{
		if (c == EOF)
			break;
		if (isspace(c) || isalpha(c))
			putchar(c);
	}
	return 0;
}
