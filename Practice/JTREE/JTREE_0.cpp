#include<bits/stdc++.h>
using namespace std;

int n, m, h;
long long a[100005];
long long tree[400005];
vector<int> adj[100005];
vector<pair<int, int> > tick[100005];

long long query(int cur, int l, int r, int x, int y)
{
    if(l > y || r < x || l > r)
        return 1000000000000000000LL;
    if(x == y)
        return tree[cur];
    if(l <= x && y <= r)
        return tree[cur];
    int m = x + y >> 1;
    return min(query(2 * cur, l, r, x, m), query(2 * cur + 1, l, r, m + 1, y));
}

void update(int cur, int l, int x, int y, long long v)
{
    if(l > y || l < x)
        return;
    if(x == y)
    {
        if(l == x)
        {
            tree[cur] = v;
            return;
        }
    }
    int m = x + y >> 1;
    update(2 * cur, l, x, m, v);
    update(2 * cur + 1, l, m + 1, y, v);
    tree[cur] = min(tree[2 * cur], tree[2 * cur + 1]);
}

void dfs(int source)
{
    h++;
    for(vector<pair<int, int> >::iterator it = tick[source].begin(); it != tick[source].end(); it++)
        a[source] = min(a[source], query(1, max(1, h - (*it).second), h - 1, 1, 100000) + (*it).first);
    update(1, h, 1, 100000, a[source]);
    for(vector<int>::iterator it = adj[source].begin(); it != adj[source].end(); it++)
        dfs(*it);
    h--;
}

int main()
{
    for(int i = 0; i < 100005; i++)
        a[i] = 1000000000000000000LL;
    int q, x, y;
    cin>>n>>m;
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        adj[y].push_back(x);
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &x, &q, &y);
        tick[x].push_back(make_pair(y, q));
    }

    h = 1;
    a[1] = 0;

    for(vector<int>::iterator it = adj[1].begin(); it != adj[1].end(); it++)
        dfs(*it);

    scanf("%d", &q);
    while(q--)
    {
        scanf("%d", &x);
        printf("%lld\n", a[x]);
    }
    return 0;
}
