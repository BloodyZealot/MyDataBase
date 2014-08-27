#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int start=30;
	int h1,time1,h2,time2;
	scanf("%d:%d",&h1,&time1);
	scanf("%d:%d",&h2,&time2);
	if(h1==11)time1-=start;
	if(h2==11)
		time2-=start;
	else
		time2=time2+60-start;
	int d1,d2;
	if(time1<=10)
		d1=time1*100;
	else
		if(time1<=20)
			d1=(time1-10)*150+1000;
		else
			d1=2500+(time1-20)*50;
	if(time2<=10)
		d2=time2*100;
	else
		if(time2<=20)
			d2=(time2-10)*150+1000;
		else
			d2=2500+(time2-20)*50;
	cout<<d2-d1;
	return 0;
}