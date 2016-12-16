#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n;
	double a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<1500)
		{
			c=n+0.1*n+0.9*n;	
		}
		else
		{
			c=500+0.98*n+n;
		
		}
		cout<<c<<endl;
	}
	return 0;
} 

