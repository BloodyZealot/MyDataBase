#include<iostream>
#include<string>

using namespace std;

bool issafe(string& s)
{
	int A=0,a=0,n=0,o=0;
	int size=s.size();
	if(size<8||size>16)
		return false;
	else
	{
		for(int i=0;i!=size;++i)
		{
			if(isdigit(s[i]))
			{n=1;continue;}
			if(isupper(s[i]))
			{A=1;continue;}
			if(islower(s[i]))
			{a=1;continue;}
			switch(s[i])
			{
			case '@':case'^':case'~':case'%':case'#':case'!':case'$':
				o=1;
			}
		}
	}
	return (A+a+n+o)>2;
}

int main()
{
	int n;
	cin>>n;
	string s;
	for(int i=0;i!=n;++i)
	{
		cin>>s;
		if(issafe(s))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}