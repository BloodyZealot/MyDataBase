#include<iostream>
#include<vector>
using namespace std;

int num=1;

struct stick
{
	int n;
	float x1,y1,x2,y2,linear;
};

istream& operator>> (istream& in,stick& s)
{
	s.n=num++;
	in>>s.x1>>s.y1>>s.x2>>s.y2;
	s.linear=(s.y2-s.y1)/(s.x2-s.x1);
	return in;
}

ostream& operator<< (ostream& out,stick& s)
{
	out<<s.n;
	return out;
}

bool isup(stick& s1,stick& s2)
{
	float temp1=s2.y1-s1.y1-(s2.x1-s1.x1)*s1.linear,
			 temp2=s2.y2-s1.y1-(s2.x2-s1.x1)*s1.linear;
	if(temp1*temp2<0)
	{
		temp1=s1.y1-s2.y1-(s1.x1-s2.x1)*s2.linear,
		 temp2=s1.y2-s2.y1-(s1.x2-s2.x1)*s2.linear;
		return temp1*temp2<0;
	}
	return 0;
}

int main()
{
	int n;
	vector<stick> place;
	vector<stick>::iterator  obeg,oend;
	stick temp;
	while(cin>>n)
	{
		if(n==0)
			return 0;
		num=1;
		cin>>temp;
		place.push_back(temp);
		for(int i=1;i!=n;++i)
		{
			cin>>temp;
			for(obeg=place.begin(),oend=place.end();obeg!=oend;)
			{
				if(isup(*obeg,temp))
				{
					obeg=place.erase(obeg);
					oend=place.end();
				}
				else
					++obeg;
			}
			place.push_back(temp);
		}
		cout<<"Top sticks: ";
		for(obeg=place.begin(),oend=--(place.end());
				obeg!=oend;++obeg)
				cout<<*obeg<<", ";
		cout<<*obeg<<"."<<endl;
		place.clear();
	}
	return 0;
}