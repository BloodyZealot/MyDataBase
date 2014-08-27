#include<iostream>

using namespace std;

void print(int a,int b)
{
	for(int i=0;i!=b;++i)
		cout<<" ";
	cout<<"X";
	for(int i=0;i!=a;++i)
		cout<<" ";
	if(a)cout<<"X";
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	int a,b;
	for(int i=0;i!=n;++i)
	{
		cin>>a>>b;
		int tempa=a-2,tempb=0;
		bool decrease=1;
		for(int j=0;j!=b;)
		{
			print(tempa,tempb);
			if(decrease)
			{
				if(tempa==1)
				{tempa=0;decrease=0;}
				else
					tempa-=2;
				tempb++;
			}
			else
			{
				if(tempa==a-2)
				{
					tempa-=2;tempb=1;
					j++;decrease=1;
				}
				else
				{
					if(tempa==0)
						tempa=1;
					else
						tempa+=2;
					tempb--;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}