#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

ll MOD = 1000000007,dp[102][102];
int n,a[101];

ll solve(ll i,ll j)
{
    int k;
    if(dp[i][j]!=-1)return dp[i][j];
        dp[i][j]=0;
        dp[i][j]=(dp[i][j]+solve(i+1,j))%MOD;
        if(a[i]<0)
        for(k=j;k>i;k--)
        {
            if(a[k]+a[i]==0)
            dp[i][j]=(dp[i][j]+(solve(i+1,k-1)*solve(k+1,j))%MOD)%MOD;
        }
  //  cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    int i,j;

    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(i=0;i<=n+1;i++)
    for(j=0;j<i;j++)
    dp[i][j]=1;


    for(i=1;i<=n;i++)
    cin>>a[i];

    cout<<solve(1,n)<<endl;
    return 0;
}


// ^_^ \\
