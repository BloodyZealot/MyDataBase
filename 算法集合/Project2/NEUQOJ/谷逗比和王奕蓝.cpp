#include<iostream>

using namespace std;

int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(!n)return 0;
		n*=n;
		n-=1;
		if(n%2==0)
			cout<<"Yilan"<<endl;
		else
			cout<<"Roliygu"<<endl;
	}
	return 0;
}