#include<bits/stdc++.h>
using namespace std;

long long num, denom;
int n, m;
bool a[100005];
vector<pair<int, int> >adj[100005];
int dp[100005];

void dfs(int source, int parent)
{
    for(vector<pair<int, int> >::iterator it = adj[source].begin(); it != adj[source].end(); it++)
    {
        if((*it).first == parent)
            continue;
        dfs((*it).first, source);
        dp[source] += dp[(*it).first];
    }
    if(a[source] == 1)
        dp[source]++;
    for(vector<pair<int, int> >::iterator it = adj[source].begin(); it != adj[source].end(); it++)
    {
        if((*it).first == parent)
            continue;
        num += 1LL * (m - dp[(*it).first]) * (dp[(*it).first]) * ((*it).second);
    }
}

int main()
{
    int t, x, y, w;
    cin>>t;
    while(t--)
    {
        for(int i = 0; i < 100005; i++)
        {
            adj[i].clear();
            dp[i] = 0;
            a[i] = 0;
        }

        scanf("%d %d", &n, &m);
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d %d %d", &x, &y, &w);
            adj[x].push_back(make_pair(y, w));
            adj[y].push_back(make_pair(x, w));
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &x);
            a[x] = 1;
        }
        denom = 1LL * m * m;
        num = 0;
        dfs(1, 1);
        num = 2LL * num;

        long long g = __gcd(num, denom);
        num /= g;
        denom /= g;

        printf("%lld %lld\n", num, denom);
    }
    return 0;
}
