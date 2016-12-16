#include<bits/stdc++.h>
using namespace std;

int a[1002];

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,i,s;
    cin>>t;
    while(t--)
    {
    	s=0;
    	cin>>n;
    	for(i=1;i<=n;i++)cin>>a[i];
    	sort(a,a+n+1);
    	i=n;
    	while(i>=0)
    	{
    		s+=(a[i]+a[i-1]);
    		i-=4;
    	}
	cout<<s<<endl;
    }
    return 0;
}
