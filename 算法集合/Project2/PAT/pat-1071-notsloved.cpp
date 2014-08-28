#include<iostream>
#include<map>
#include<string>

using namespace std;

map<string, int> dict;
map<string, int>::iterator begptr, endptr, result;
string word,temp;
int size, index;
int starter, ender;
int maxtime;

int main()
{
	getline(cin, word);
	size = word.size();
	starter = index = 0; ender = 0;
	for (; index != size; ++index)
	{
		if (isalnum(word[index]))
			ender++;
		else
		{
			if (ender != 0)
			{
				temp = string(word, starter, ender);
				for (starter=0; starter != ender; ++starter)
					temp[starter]=tolower(temp[starter]);
				++dict[temp];
				 ender = 0;
			}
			starter = index+1;
		}
	}
	maxtime = 0;
	begptr = dict.begin();
	endptr = dict.end();
	for (; begptr != endptr; ++begptr)
	{
		if (begptr->second > maxtime)
		{
			maxtime = begptr->second;
			result = begptr;
		}
	}
	cout << result->first << " " << result->second;
	return 0;
}