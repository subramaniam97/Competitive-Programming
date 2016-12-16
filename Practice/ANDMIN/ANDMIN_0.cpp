#include<bits/stdc++.h>
using namespace std;

int a[100005];
pair<int, int> tree[400005];

void build(int i, int l, int r)
{
    if(l > r)
        return;
    if(l == r)
    {
        tree[i].first = a[l];
        tree[i].second = a[l];
        return;
    }
    int m = l + r >> 1;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    tree[i].first = min(tree[2 * i].first, tree[2 * i + 1].first);
    tree[i].second = tree[2 * i].second | tree[2 * i + 1].second;
}

int query(int i, int l, int r, int x, int y)
{
    if(l > r || r < x || y < l)
        return INT_MAX;
    if(x <= l && r <= y)
        return tree[i].first;
    int m = l + r >> 1;
    return min(query(2 * i, l, m, x, y), query(2 * i + 1, m + 1, r, x, y));
}

void update(int i, int l, int r, int x, int y, int n)
{
    if(l > r || r < x || y < l)
        return;
    if(l == r)
    {
        a[l] = a[l] & n;
        tree[i].first = tree[i].first & n;
        tree[i].second = tree[i].second & n;
        return;
    }
    if(tree[i].second & (~n))
    {
        int m = l + r >> 1;
        update(2 * i, l, m, x, y, n);
        update(2 * i + 1, m + 1, r, x, y, n);
        tree[i].first = min(tree[2 * i].first, tree[2 * i + 1].first);
        tree[i].second = tree[2 * i].second | tree[2 * i + 1].second;
    }
}

int main()
{
    int n, q;
    int c, l, r, x;
    cin>>n>>q;
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    while(q--)
    {
        scanf("%d", &c);
        if(c == 0)
        {
            scanf("%d %d", &l, &r);
            printf("%d\n", query(1, 1, n, l, r));
        }
        else
        {
            scanf("%d %d %d", &l, &r, &x);
            update(1, 1, n, l, r, x);
        }
    }
    return 0;
}
