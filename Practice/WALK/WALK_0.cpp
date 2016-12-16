#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,i,r,a[100002];
    cin>>t;
    while(t--)
    {
    	r=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=n;i>0;i--)
	{
		r=max(a[i],r+1);
	}
	cout<<r<<endl;
    }
    return 0;
}
