#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[100005];
int tree[400005];
bool one[400005];
int b[1000005];

void pre()
{
    memset(b, -1, sizeof(b));
    for(int i = 2; i * i <= 1000000; i++)
        for(int j = i; j <= 1000000; j += i)
            if(b[j] == -1)
                b[j] = i;
    for(int i = 1; i <= 1000000; i++)
        if(b[i] == -1)
            b[i] = i;
}


void build(int cur, int x, int y)
{
    if(x > y)
        return;
    if(x == y)
    {
        tree[cur] = b[a[x]];
        return;
    }
    int m = x + y >> 1;
    build(2 * cur, x, m);
    build(2 * cur + 1, m + 1, y);
    tree[cur] = max(tree[2 * cur], tree[2 * cur + 1]);
}

int query(int cur, int l, int r, int x, int y)
{
    if(l > y || r < x || l > r)
        return 0;
    if(x == y)
        return tree[cur];
    if(l <= x && y <= r)
        return tree[cur];
    int m = x + y >> 1;
    return max(query(2 * cur, l, r, x, m), query(2 * cur + 1, l, r, m + 1, y));
}

void update(int cur, int l, int r, int x, int y)
{
    if(l > y || r < x || l > r)
        return;
    if(x == y)
    {
        if(l <= x && x <= r)
        {
            a[x] /= b[a[x]];
            tree[cur] = b[a[x]];
        }
        return;
    }
    int m = x + y >> 1;
    if(tree[2 * cur] != 1)
        update(2 * cur, l, r, x, m);
    if(tree[2 * cur + 1] != 1)
        update(2 * cur + 1, l, r, m + 1, y);
    tree[cur] = max(tree[2 * cur], tree[2 * cur + 1]);
}

int main()
{
    pre();
    int t, c, l, r;
    cin>>t;
    while(t--)
    {
        vector<int> res;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%d", a + i);

        build(1, 1, n);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &c, &l, &r);
            if(c)
                printf("%d ",query(1, l, r, 1, n));
            else
                update(1, l, r, 1, n);
        }
        printf("\n");
    }
    return 0;
}
