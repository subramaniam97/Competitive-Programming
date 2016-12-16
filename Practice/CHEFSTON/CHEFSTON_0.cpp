#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int w[100000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n,v,k;
	ll ans;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>w[i];
		}

		for(int i=0;i<n;i++)
		{
			cin>>v;
			ans=max(ans,(1LL)*(k/w[i])*v);
		}
		cout<<ans<<endl;
	}
}