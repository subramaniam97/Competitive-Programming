#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	long long int t,l,r,a,b,c;
	cin>>t;
	while(t--)
	{
		c=0;
		cin>>l>>r;
		if(l==1)c++;
		a=2;
		while(a<=r)
		{
			b=a;
			while(b<=r)
			{
			    if(l<=b&&b<=r)
				c++;
				b*=3;
			}
			a*=2;
		}
		cout<<c<<endl;
	}
	return 0;
}