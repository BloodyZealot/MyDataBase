#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	string in,out;
	map<char,int> dict;
	cin>>in>>out;
	int size=in.size();
	int size2=out.size();
	for(int i=0,j=0;i!=size;++i)
	{
		if(j!=size2&&in[i]==out[j])
			j++;
		else
		{
			if(dict[toupper(in[i])]++==0)
				cout<<char(toupper(in[i]));
		}
	}
	return 0;
}