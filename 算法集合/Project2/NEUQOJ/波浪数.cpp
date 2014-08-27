#include<iostream>
#include<string>
using namespace std;
bool isbolang(int num,int minc,int maxc,int n)
{
	int temp,i1,i2,tn=0;
	bool in=0;
	for(;minc<=maxc&&tn<=n;++minc)
	{
		temp=num;
		i1=temp%minc;
		temp/=minc;
		i2=temp%minc;
		temp/=minc;
		if(i1==i2)
			continue;
		while(temp!=0)
		{
			in=1;
			if(i1!=temp%minc)
				break;
			temp/=minc;
			if(i2!=temp%minc)
				break;
			temp/=minc;
		}
		if(temp!=0&&in)
			continue;
		tn+=1;
	}
	return tn==n;
}
int main()
{
	int minc,maxc,minn,maxn,n;
	while(cin>>minc>>maxc>>minn>>maxn>>n)
		for(;minn<=maxn;++minn)
		{
			if(isbolang(minn,minc,maxc,n))
				cout<<minn<<endl;
		}
	return 0;
}