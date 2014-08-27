#include<iostream>
#include<algorithm>

using namespace std;
 
 
bool fun(int n)
{
    while(n!=0)
    {
        switch(n%10)
        {
        case 2:case 3:case 5: case 7:
            n/=10;break;
        default:
            return false;
        }
    }
    return true;
}
 
int main()
{
	int arr1[500],arr2[50];
	int t1,t2,t3;
	int *beg1,*beg2,*end1,*end2;
	int i,j;
	for(i=222,j=0;i!=778;++i)
	{
		if(fun(i))
			arr1[j++]=i;
	}
	beg1=arr1,end1=arr1+j;
	for(i=22,j=0;i!=78;++i)
	{
		if(fun(i))
			arr2[j++]=i;
	}
	beg2=arr2,end2=arr1+j;
	for(beg1=arr1;beg1!=end1;++beg1)
		for(beg2=arr2;beg2!=end2;++beg2)
		{
			t3=(*beg1)*(*beg2);
			if(fun(t3))
			{
				t1=(*beg1)*(*beg2%10);
				t2=(*beg1)*(*beg2/10);
				if(fun(t1)&&fun(t2))
				{
					cout<<*beg1<<endl<<*beg2<<endl<<
						t1<<endl<<t2<<endl<<t3;
					return 0;
				}
			}
		}
	return 0;
}