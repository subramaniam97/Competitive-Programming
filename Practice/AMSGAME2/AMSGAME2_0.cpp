#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll a[61],n;
ll dp[61][10001];

ll solve(ll cur,ll gcd)
{
    if(cur>=n&&gcd==1)return 1;
    if(cur>=n&&gcd!=1)return 0;
    if(dp[cur][gcd]!=-1)return dp[cur][gcd];
    ll r=0;
    r+=solve(cur+1,gcd)+solve(cur+1,__gcd(gcd,a[cur]));
    return dp[cur][gcd]=r;
}

int main()
{
    ll t,r;
    scanf("%lld",&t);
    while(t--)
    {
        r=0;
        memset(dp,-1,sizeof(dp));
        scanf("%lld",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            r+=solve(i+1,a[i]);
        }
        printf("%lld\n",r);
    }
    return 0;
}
