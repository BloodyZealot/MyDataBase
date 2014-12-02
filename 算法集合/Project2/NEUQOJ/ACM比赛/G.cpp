#include<iostream>
#include<string>

using namespace std;

string a[] = {
	"system",
	"scanner",
	"string",
	"math",
	"tolowercase",
	"touppercase",
};
string b[] = {
	"System",
	"Scanner",
	"String",
	"Math",
	"toLowerCase",
	"toUpperCase"
};

int main()
{
	char c;
	string p;
	string::iterator tier;
	while (c = getchar())
	{
		if (isalpha(c))
			p.push_back(c);
		else
		{
			if (p.size())
			{
				for (int i = 0; i != 6; ++i)
					if (p.find(a[i]) != string::npos)
						p.replace(p.find(a[i]), a[i].size(), b[i]);
				cout << p;
				p.clear();
			}
			if (c == EOF)
				break;
			cout << c;
		}
	}
	return 0;
}