#include<iostream>
#include<string>
#include<set>
#include<bitset>
#include<algorithm>

using namespace std;


int l,c;
int yuan,fu;
int size;

inline bool isok(string& s)
{
	yuan=0;fu=0;
	for(int i=0;i!=l;++i)
		switch(s[i])
		{
		case 'a' :case'e':case 'i':case 'o':case 'u':
			yuan++;break;
		default:
			fu++;
		}
	return yuan>0&&fu>1;
}

void makenext(int *a)
{
	++a[l-1];
	for(int i=l-1,j=0;i!=0;--i,++j)
	{
		if(a[i]==size-j)
			{
				a[i]=-1;
				a[i-1]++;
			}
	}
	for(int i=1;i!=l;++i)
	{
		if(a[i]==-1)
			a[i]=a[i-1]+1;
	}
}

int main()
{
	cin>>l>>c;
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	int *a=new int[l];
	for(int i=0;i!=l;++i)
		a[i]=i;
	set<string> se;
	string temp;
	size=s.size();
	while(a[0]!=size-l+1)
	{
		for(int i=0;i!=l;++i)
			temp.push_back(s[a[i]]);
		if(isok(temp))
			se.insert(temp);
		makenext(a);
		temp.clear();
	}
	set<string>::iterator beg=se.begin(),end=se.end();
	for(;beg!=end;++beg)
		cout<<*beg<<endl;
}