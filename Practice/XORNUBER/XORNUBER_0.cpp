#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1)
		{
			m=2;
			goto a;
		}
		if(!(n&(n+1)))m=n>>1;
		else m=-1;	
		a:
		cout<<m<<endl;
	}
	return 0;
}