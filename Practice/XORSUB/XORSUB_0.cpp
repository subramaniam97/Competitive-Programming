#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

ll MOD = 1000000007;

ll raise(ll b, ll exp)
{
    ll r=1;
    while(exp)
    {
        if(exp&1)r=(r*b)%MOD;
        b=(b*b)%MOD;
        exp>>=1;
    }
    return r;
}

bool dp[1024];
int a[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,k,i,j,r;
    cin>>t;
    while(t--)
    {
    	r=INT_MIN;
    	memset(dp,0,sizeof(dp));
	cin>>n>>k;
	for(i=0;i<n;i++)
	cin>>a[i];
	dp[0]=1;
	for(i=0;i<n;i++)
	{
		for(j=1;j<=1023;j++)
		{
			dp[j]=dp[j]|dp[j^a[i]];
		}
	}
	for(i=0;i<1024;i++)
	{
		r=max(r,dp[i]*(i^k));
	}
	cout<<r<<endl;
	
    }
    return 0;
}


// ^_^ \\