#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	long long int m,r,n,q,i;
	cin>>n>>q;
	for(i=0;i<q;i++)
	{
		cin>>m;
		if(m<=2*n+1)
		{
			r=max(m-n-1,(long long)0);
		}
		else
		{
			r=max(3*n-m+1,(long long)0);
		}
		cout<<r<<endl;
	}
	return 0;
}