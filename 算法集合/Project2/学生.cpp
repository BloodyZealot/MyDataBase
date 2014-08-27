#include<iostream>
#include<string>
#include<set>
using namespace std;

struct student
{
	string sno;
	string name;
	int s1,s2,s3,save;
};

bool operator< (const student& s1,const student& s2)
{
	return s1.save>s2.save;
}

int main()
{
	int n;
	cin>>n;
	student temp;
	//set<student> s;
	//int av1=0,av2=0,av3=0;
	for(int i=0;i!=n;++i)
	{
		cin>>temp.sno>>temp.name>>temp.s1>>temp.s2>>temp.s3;
		cout<<temp.sno<<","<<temp.name<<","<<temp.s1<<","<<temp.s2<<","<<temp.s3<<endl;
		//av1+=temp.s1;av2+=temp.s2;av3+=temp.s3;
		//temp.save=(temp.s1+temp.s2+temp.s3)/3;
		//s.insert(temp);
	}
	//cout<<av1/n<<" "<<av2/n<<" "<<av3/n<<endl;
	//temp=*(s.begin());
	//cout<<temp.sno<<" "<<temp.name<<" "<<temp.s1<<" "<<temp.s2<<" "<<temp.s3;
	return 0;
}