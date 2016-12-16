#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

ll MOD = 1000000007,n,k;
ll memo[1001][11];

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

ll dp(ll cur, ll pla)
{
	ll i;
	if(cur==0&&pla==0)return 1;
	if(cur==0&&pla!=0)return 0;
	if(memo[cur][pla]!=-1)return memo[cur][pla];
	memo[cur][pla]=0;
	for(i=0;i<=k;i++)
	{
	    if(i!=pla)
	    memo[cur][pla] = (memo[cur][pla]+dp(cur-1,i))%MOD;
	}
	return memo[cur][pla];
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
    	memset(memo,-1,sizeof(memo));
	cin>>n>>k;
	cout<<dp(n,0)<<endl;
    }
    return 0;
}


// ^_^ \\