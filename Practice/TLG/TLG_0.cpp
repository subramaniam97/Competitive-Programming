#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,a,b,l=0,m=0,p;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		l+=a-b;
		if(fabs(l)>m)
		{
			m=fabs(l);
			if(l<0)p=2;
			else p=1;
		}
		
	}
	cout<<p<<" "<<m;
	return 0;
}