#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<sstream>
using namespace std;

class bignumber
{
public:
	bignumber(int num){data.push_back(num);}
	bignumber(string& s);
	void operator*= (int num);
	friend bignumber operator* (bignumber& b1,bignumber& b2);
	void operator= (int num){
		data.clear();
		data.push_back(num);
	}
	bignumber&  operator+= (bignumber& b2);
	void output();
private:
	vector<int> data;
};
bignumber::bignumber(string& s)
{
	int i;
	int size=s.size()%6;
	string temp;
	for(i=s.size()-6;i>=size;i-=6)
	{
		temp=s.substr(i,6);
		data.push_back(atoi(temp.c_str()));
	}
	if(size)
	{
		temp=s.substr(0,size);
		data.push_back(atoi(temp.c_str()));
	}
}
bignumber operator * (bignumber& b1,bignumber& b2)
{
	bignumber result(0);
	int size1=b1.data.size(),size2=b2.data.size();
	result.data.resize(size1+size2+1,0);
	for(int i=0;i!=size1;++i)
		for(int j=0;j!=size2;++j)
		{
			result.data[i+j]+=b1.data[i]*b2.data[i];
			if(result.data[i+j]>=1000000)
			{
				result.data[i+j+1]+=result.data[i+j]/1000000;
				result.data[i+j]%=1000000;
			}
		}
	int size=result.data.size()-1;
	for(int i=0;i!=size;++i)
	{
		if(result.data[i]>=1000000)
		{
			result.data[i+1]+=result.data[i]/1000000;
			result.data[i]%=1000000;
		}
	}
	if(result.data[size]>=1000000)
	{
		result.data.push_back(result.data[size]/1000000);
		result.data[size]%=1000000;
	}
	return result;
}
void bignumber::operator *=(int num)
{
	int size=data.size();
	for(int j=0;j!=size;++j)
		data[j]*=num;
	size--;
	for(int i=0;i!=size;++i)
	{
		if(data[i]>=1000000)
		{
			data[i+1]+=data[i]/1000000;
			data[i]%=1000000;
		}
	}
	if(data[size]>=1000000)
	{
		data.push_back(data[size]/1000000);
		data[size]%=1000000;
	}
}
bignumber& bignumber::operator+= (bignumber& b2)
{
	int min,trans;
	if(b2.data.size()>data.size())
	{
		min=data.size();
		trans=b2.data.size()-data.size();
	}
	else
	{
		min=b2.data.size();
		trans=0;
	}
	for(int i=0;i!=min;++i)
		data[i]+=b2.data[i];
	for(int i=0;i!=trans;++i)
		data.push_back(b2.data[min+i]);
	int size=data.size()-1;
	for(int i=0;i!=size;++i)
	{
		if(data[i]>=1000000)
		{
			data[i+1]+=data[i]/1000000;
			data[i]%=1000000;
		}
	}
	if(data[size]>=1000000)
	{
		data.push_back(data[size]/1000000);
		data[size]%=1000000;
	}
	return *this;
}
void bignumber::output()
{
	cout<<setw(0);
	int size=data.size();
	cout<<data[size-1];
	for(int i=size-2;i>=0;--i)
	{
		cout<<setw(6)<<setfill('0')<<data[i];
	}
	cout<<setw(0);
	cout<<endl;
}

int main()
{
	bignumber big(1);
	for(int i=2;i!=1998;++i)
	{
		big*=i;
	}
	big.output();
	return 0;
}
/*int main()
{
	bignumber temp(1),result(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
			temp*=i;
		temp.output();
		result+=temp;
		result.output();
	}
	result.output();
	return 0;
}*/
/*
int main()
{
	string s,s1;
	cin>>s>>s1;
	bignumber b1(s),b2(s1),b3(0);
	b3=b1*b2;
	b3.output();
	return 0;
}
*/