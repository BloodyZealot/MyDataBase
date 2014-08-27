#include<iostream>
#include<stack>
#include<string>
#include<sstream>
#include<iomanip>
#include<algorithm>

using namespace std;

float calculate(stack<float>& st,char cal)
{
	float temp2=st.top();
	st.pop();
	float temp1=st.top();
	st.pop();
	switch(cal)
	{
	case'+':
		return temp1+=temp2;
	case '-':
		return temp1-=temp2;
	case '*':
		return temp1*=temp2;
	case '/':
		return temp1/=temp2;
	}
	return 0;
}

int main()
{
	stack<float> st;
	int n;
	cin>>n;
	string s;
	char cal;
	stringstream ss;
	cin.get();
	for(int i=0;i!=n;++i)
	{
		getline(cin,s);
		replace(s.begin(),s.end(),' ','$');
		ss<<s;
		s.clear();
		while(ss>>cal)
		{
			switch(cal)
			{
			case '+':case '-':case '*':case '/':
				st.push(calculate(st,cal));break;
			case '$':
				{
					if(s.size())
					{
						st.push(atof(s.c_str()));
						s.clear();
					}
					break;
				}
			default:
					s.push_back(cal);
			}
		}
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<st.top()<<endl;
		ss.clear();
		while(!st.empty())
			st.pop();
	}
	return 0;
}