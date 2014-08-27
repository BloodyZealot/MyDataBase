#include<iostream>
#include<string>
#include<cstdlib>
#include<bitset>
using namespace std;


int main()
{
	bitset<32> bit,temp;
	int n;
	while(cin>>n)
	{
		if(n==0)
			return 0;
		for(bit=1<<n++;bit[n]!=1;bit=bit.to_ulong()+1)
		{
			for(temp=2;temp!=bit;temp=temp.to_ulong()+1)
				if(bit.to_ulong()%temp.to_ulong()==0)
					break;
			if(bit==temp)
			{
				cout<<bit<<endl;
				break;
			}
		}
	}
}