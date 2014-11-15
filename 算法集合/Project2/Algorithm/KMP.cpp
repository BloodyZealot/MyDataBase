#include<string>
#include<vector>
using std::vector;
using std::string;
//for test
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

string::size_type KMP(const string& str, const string& substr)
{
	string::size_type strsize(str.length()), substrsize(substr.length());
	if (strsize == 0 || substrsize == 0)
		return string::npos;
	//initalize the index of backtrack
	vector<string::size_type> prev(substrsize);
	prev[0] = string::npos;
	for (size_t i = 0, j = 1; j != substrsize; ++j)
	{
		if (substr[i] == substr[j])
			prev[j] = i++;
		else
		{
			prev[j] = i;
			i = 0;
		}
	}
	for (size_t i = 1; i != substrsize; ++i)
	{
		if (substr[i] == substr[prev[i]])
			prev[i] = prev[prev[i]];
	}

	string::size_type index = 0, subindex = 0;
	for (; subindex != substrsize&&index != strsize;)
	{
		if (str[index] == substr[subindex])
		{
			++index; ++subindex;
		}
		else
		{
			if (prev[subindex] == string::npos)
				++index;
			else
				subindex = prev[subindex];
		}
	}
	if (subindex == substrsize)
		return index-substrsize;
	else
		return string::npos;
}


int main()
{
	string s1 = "BBC ABCDAB ABCDABCDABDE";
	string s2 = "ABCDABD";
	string::size_type result = KMP(s1, s2);
	cout << result<<endl<<s1.substr(result,s2.length());
	system("pause");
	return 0;
}