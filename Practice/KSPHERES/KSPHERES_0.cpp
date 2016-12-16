#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long int dp[1002][1002],e[1002],f[1002];

int main()
{
    ios_base::sync_with_stdio(0);
    int k,i,n,j,m,c,x,mx=INT_MIN;

    cin>>n>>m>>c;
    for(i=1;i<=n;i++){cin>>x; mx=max(mx,x);  e[x]++;}
    for(i=1;i<=m;i++){cin>>x;  f[x]++;}

    k=1;
    for(i=1;i<=mx;i++)
        {
            if(e[i]==0||f[i]==0)continue;
            e[k++]=((e[i]%MOD)*(f[i]%MOD))%MOD;
        }
e[k]=0;
    for(i=1;i<=k;i++)
    {
        dp[i][0]=dp[i-1][0]+e[i];
    }

    for(i=2;i<=k;i++)
    {
        for(j=1;j<i;j++)
        {
            dp[i][j]=((((dp[i-1][j-1]%MOD)*(e[i]))%MOD)+(dp[i-1][j]))%MOD;
        }
    }


    for(i=1;i<k;i++)cout<<dp[k][i]<<" ";
    for(;i<=c;i++)cout<<"0 ";

    return 0;
}
