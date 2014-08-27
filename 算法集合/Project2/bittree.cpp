#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n=1;

void split(string& pre,string& post)
{
	int strsize=pre.size()-1;
	if(strsize<0)	return;
	int pos=post.find(*pre.begin());
	if(pos==strsize)
	{
		n*=2;
		pre.erase(pre.begin());
		post.erase(--post.end());
		split(pre,post);
	}
	else
	{
		string lpre=pre.substr(1,pos),
				   rpre=pre.substr(pos+1),
				   lpost=post.substr(0,pos),
				   rpost=post.substr(pos+1);
		rpre.erase(rpre.begin());
		rpost.erase(--rpost.end());
		split(lpre,lpost);
		split(rpre,rpost);
	}
}

int main()
{
	string pre,post;
	while(cin>>pre>>post)
	{
		n=1;
		pre.erase(pre.begin());
		post.erase(--post.end());
		split(pre,post);
		cout<<n<<endl;
	}
	return 0;
}