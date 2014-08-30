#include <iostream>  
#include <cstring> 
#include<string>

using namespace std;



int LCS(string str1, int len1, string str2, int len2, string &lcs)
{
	if (str1.size()==0 ||str2.size()==0)
		return -1;  
	int *c = new int[len2 + 1];
	for (int i = 0; i < len2; ++i)
		c[i] = 0;
	int max_len = 0;    
	int pos = 0;        
	for (int i = 0; i < len1; ++i)
	{
		for (int j = len2; j > 0; --j)  
		{
			if (str1[i] == str2[j - 1])
			{
				c[j] = c[j - 1] + 1;
				if (c[j] > max_len)
				{
					max_len = c[j];
					pos = j - 1;
				}
			}
			else
			{
				c[j] = 0;
			}
		}
	}

	if (0 == max_len)
	{
		delete[] c;
		return 0;
	}
	lcs = str2.substr(pos - max_len + 1, max_len);
	delete[] c;
	return max_len;
}

int main()
{
	const char *str1 = "abacaba";
	const char *str2 = "caba";
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	string lcs;
	int len = LCS(str1, len1, str2, len2, lcs);
	cout << "max length = " << len << endl;
	cout << lcs;
	return 0;
}