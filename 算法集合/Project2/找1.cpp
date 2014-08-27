#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	long i,j;
	int n;
	while(1){
	cin>>i>>j;
	if(i>j)
		swap(i,j);
	if(j==0&&i==j)
		break;
	n=0;
	string str;
	stringstream strs;
		for(;i<=j;++i){
			strs<<i;
			strs>>str;
			n+=count(str.begin(),str.end(),'1');
			strs.clear();
		}
		cout<<n<<endl;
	}
	return 0;
}