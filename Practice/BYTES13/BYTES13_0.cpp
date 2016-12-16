#include<bits/stdc++.h>
using namespace std;

int a[400005];
int segtree[400005];
int lazy[400005];

void build(int l, int r, int i)
{
    if(l == r)
    {
        segtree[i] = a[l];
        return;
    }
    int m = l + r >> 1;
    build(l, m, 2 * i + 1);
    build(m + 1, r, 2 * i + 2);
    segtree[i] = segtree[2 * i + 1] + segtree[2 * i + 2];
}

void update(int l, int r, int x, int y, long long int z, int i)
{
    if(lazy[i] == 2)
    {
        segtree[i] = 0;
        if(l != r)
            lazy[2 * i + 1] = lazy[i];
        if(l != r)
            lazy[2 * i + 2] = lazy[i];
        lazy[i] = 0;
    }
    if(lazy[i] == 1)
    {
        segtree[i] = r - l + 1;
        if(l != r)
            lazy[2 * i + 1] = lazy[i];
        if(l != r)
            lazy[2 * i + 2] = lazy[i];
        lazy[i] = 0;
    }
    if(r < x || l > y)
        return;
    if(x <= l && r <= y)
    {
        if(z & (z - 1))
        {
            segtree[i] = 0;
            a[l] = 0;
            if(l != r)
                lazy[2 * i + 1] = 2;
            if(l != r)
                lazy[2 * i + 2] = 2;
        }
        else
        {
            segtree[i] = r - l + 1;
            a[l] = 1;
            if(l != r)
                lazy[2 * i + 1] = 1;
            if(l != r)
                lazy[2 * i + 2] = 1;
        }
        return;
    }
    int m = l + r >> 1;
    update(l, m, x, y, z, 2 * i + 1);
    update(m + 1, r, x, y, z, 2 * i + 2);
    segtree[i] = segtree[2 * i + 1] + segtree[2 * i + 2];
}

int query(int l, int r, int x, int y, int i)
{
    if(lazy[i] == 2)
    {
        segtree[i] = 0;
        if(l != r)
            lazy[2 * i + 1] = lazy[i];
        if(l != r)
            lazy[2 * i + 2] = lazy[i];
        lazy[i] = 0;
    }
    if(lazy[i] == 1)
    {
        segtree[i] = r - l + 1;
        if(l != r)
            lazy[2 * i + 1] = lazy[i];
        if(l != r)
            lazy[2 * i + 2] = lazy[i];
        lazy[i] = 0;
    }
    if(r < x || l > y)
        return 0;
    if(x <= l && r <= y)
        return segtree[i];
    int m = l + r >> 1;
    return query(l, m, x, y, 2 * i + 1) + query(m + 1, r, x, y, 2 * i + 2);
}

int main()
{
    int n,q,x,y;
    long long int z,c;
    scanf("%d %d",&n,&q);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld",&c);
        if(c & (c - 1))
            a[i] = 0;
        else
            a[i] = 1;
    }
    build(0, n - 1, 0);
    while(q--)
    {
        scanf("%lld",&c);
        if(c == 0)
        {
            scanf("%d %d %lld",&x,&y,&z);
            update(0, n - 1, x, y, z, 0);
        }
        else
        {
            scanf("%d %d",&x,&y);
            printf("%d\n",query(0, n - 1, x, y, 0));
        }
    }
    return 0;
}
