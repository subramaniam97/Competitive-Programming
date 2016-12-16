#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll MOD = 1000000007;

int a[1001],m,n,s;
ll dp[1001][1001];

ll solve(int cur, int p)
{
    if(cur > n || cur < 1) return 0;
    if(p == m + 1 && cur == s) return 1;
    if(p == m + 1 && cur != s) return 0;
    if(dp[cur][p] != -1) return dp[cur][p];
    return dp[cur][p] = (solve(a[p] + cur, p + 1) + solve(cur - a[p], p + 1))%MOD;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n>>m>>s;
        for(int i = m; i >= 1; i--)
            cin>>a[i];
        for(int i = 1; i <= n; i++)
            cout<<solve(i,1)<<" ";
        cout<<endl;
    }
    return 0;
}
