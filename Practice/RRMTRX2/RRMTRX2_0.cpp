#include<bits/stdc++.h>
#define MOD 10000007
using namespace std;

int a[50][50];
int n, m;
long long dp[50][50];

long long solve(int x, int y)
{
    if(y == m)
        return a[x][y];
    if(dp[x][y] != -1)
        return dp[x][y];
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += (a[x][y] * solve(i, y + 1)) % MOD;
        ans %= MOD;
    }
    return dp[x][y] = ans;
}

int main()
{
    long long ans = 0;
    memset(dp, -1, sizeof(dp));
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j] < 0)
                a[i][j] += MOD;
        }
    for(int i = 1; i <= n; i++)
    {
        ans += solve(i, 1);
        ans %= MOD;
    }
    cout<<ans<<endl;
    return 0;
}