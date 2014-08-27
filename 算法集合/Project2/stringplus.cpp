#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<list>
using namespace std;
string strplus(string& str1,string& str2)
{
	list<char> str;char temp;bool counter=0;
	string::reverse_iterator beg1=str1.rbegin(),beg2=str2.rbegin(),
										end1=str1.rend(),end2=str2.rend();
	while(beg1!=end1||beg2!=end2)
	{
		if(beg1!=end1&&beg2!=end2)
			temp=*(beg1++)+*(beg2++)-'0'+counter;
		else
			if(beg1!=end1)
				temp=*(beg1++)+counter;
			else
				temp=*(beg2++)+counter;
		if(temp>'9')
		{
			counter=1;
			temp-=10;
		}
		else
			counter=0;
		str.push_front(temp);
	}
	if(counter)
		str.push_front('1');
	return string(str.begin(),str.end());
}
int main()
{
	string str1,str2;
	vector<string> plus1,plus2,ans;
	int n;
	cin>>n;
	for(int i=0;i!=n;++i)
	{
		cin>>str1>>str2;
		plus1.push_back(str1);plus2.push_back(str2);
		ans.push_back(strplus(str1,str2));
	}
	for(int i=0;i!=n;++i)
		cout<<"Case "<<i+1<<":"<<endl
				<<plus1[i]<<" + "<<plus2[i]<<" = "<<ans[i]<<endl;
	return 0;
}