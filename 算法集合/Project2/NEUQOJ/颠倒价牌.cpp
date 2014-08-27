#include<iostream>
#include<map>

using namespace std;

//1 2 5 6 8 9 0

int reverse(int i)
{
	if(i%10==0)
		return 0;
	else
	{
		int temp,result=0;
		for(int k=1000;k!=0;k/=10,i/=10)
		{
			temp=i%10;
			switch(temp)
			{
			case 3:case 4:case 7:
				return 0;
			case 6:result+=9*k;break;
			case 9:result+=6*k;break;
			default: result+=temp*k;
			}
		}
		return result;
	}
}




int main()
{
	map<int,int> good,bad;
	int revpri,dprice;
	for(int i=1000;i!=10000;++i)
	{
		revpri=reverse(i);
		if(revpri)
		{
			dprice=revpri-i;
			if(dprice<-200&&dprice>-300)
				bad.insert(make_pair(dprice,i));
			if(dprice>800&&dprice<900)
				good.insert(make_pair(dprice,i));
		}
	}
	map<int,int>::iterator bbeg=bad.begin(),bend=bad.end(),gbeg,gend;
	for(;bbeg!=bend;++bbeg)
	{
		gbeg=good.begin();gend=good.end();
		for(;gbeg!=gend;++gbeg)
			if(bbeg->first+gbeg->first==558)
				cout<<bbeg->second;
	}
	return 0;
}