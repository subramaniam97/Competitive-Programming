#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

bool a[300005];
long long dp[300005];
int Z[600005];
int n, m;
string s, f;

void solve()
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 1)
            if(i != 0)
                dp[i] = (dp[i - 1] + 1 + dp[i - m]) % MOD;
            else
                dp[i] = 1;
        else
            if(i != 0)
                dp[i] = dp[i - 1];
    }
}


void solve1()
{
    string nw = f + "$" + s;
    int l = nw.length();
    int L, R, k;
    L = R = 0;
    for(int i = 1; i < l; i++)
    {
        if(i > R)
        {
            L = R = i;
            while(R < l && nw[R - L] == nw[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            k = i - L;
            if(Z[k] < R - i + 1)
                 Z[i] = Z[k];
            else
            {
                L = i;
                while(R < l && nw[R - L] == nw[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }

    for(int i = 0; i < l; i++)
        if(Z[i] == m)
            a[i - 2] = 1;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(Z, 0, sizeof(Z));
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        cin>>s>>f;
        n = s.length();
        m = f.length();
        solve1();
        solve();
        printf("%lld\n", dp[n - 1]);
    }
    return 0;
}
