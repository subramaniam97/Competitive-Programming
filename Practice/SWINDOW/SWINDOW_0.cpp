#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[100005];
int cnt[21], cnt1[21], cnt2[21];

struct HUMMA
{
    vector<pair<int, int> > god;
    int ans, siz;
}tree[400005];

void build(int cur, int l, int r)
{
    if(l > r)
        return;
    if(l == r)
    {
        if(k == 1)
            tree[cur].ans = 1;
        else
            tree[cur].ans = INT_MAX;
        tree[cur].siz = 1;
        tree[cur].god.push_back(make_pair(a[l], 1));
        return;
    }
    int m = l + r >> 1;
    build(2 * cur, l, m);
    build(2 * cur + 1, m + 1, r);

    deque<pair<int, int> > deq;
    for(vector<pair<int, int> >::reverse_iterator it = tree[2 * cur].god.rbegin(); it != tree[2 * cur].god.rend(); it++)
    {
        if(cnt[it -> first] == 0)
            deq.push_front(*it);
        cnt[it -> first]++;
    }
    for(vector<pair<int, int> >::iterator it = tree[2 * cur + 1].god.begin(); it != tree[2 * cur + 1].god.end(); it++)
    {
        if(cnt1[it -> first] == 0)
            deq.push_back(make_pair(it -> first, it -> second + tree[2 * cur].siz));
        cnt1[it -> first]++;
    }
    tree[cur].ans = min(tree[2 * cur].ans, tree[2 * cur + 1].ans);
    int p = 0, q = 0, c = 0, lim = deq.size();
    for(; p < lim; p++)
    {
        while(q < lim && c < k)
        {
            if(cnt2[deq[q].first] == 0)
                c++;
            cnt2[deq[q].first]++;
            q++;
        }
        if(c == k)
            tree[cur].ans = min(tree[cur].ans, deq[q - 1].second - deq[p].second + 1);
        if(cnt2[deq[p].first]== 1)
            c--;
        cnt2[deq[p].first]--;
    }

    memset(cnt, 0, sizeof(cnt));
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));

    for(vector<pair<int, int> >::iterator it = tree[2 * cur].god.begin(); it != tree[2 * cur].god.end(); it++)
        cnt1[it -> first]++;
    for(vector<pair<int, int> >::iterator it = tree[2 * cur + 1].god.begin(); it != tree[2 * cur + 1].god.end(); it++)
        cnt1[it -> first]++;
    for(vector<pair<int, int> >::iterator it = tree[2 * cur].god.begin(); it != tree[2 * cur].god.end(); it++)
    {
        if(cnt2[it -> first] == 0 || cnt2[it -> first] == cnt1[it -> first] - 1)
            tree[cur].god.push_back(*it);
        cnt2[it -> first]++;
    }
    for(vector<pair<int, int> >::iterator it = tree[2 * cur + 1].god.begin(); it != tree[2 * cur + 1].god.end(); it++)
    {
        if(cnt2[it -> first] == 0 || cnt2[it -> first] == cnt1[it -> first] - 1)
            tree[cur].god.push_back(make_pair(it -> first, it -> second + tree[2 * cur].siz));
        cnt2[it -> first]++;
    }

    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));

    tree[cur].siz = tree[2 * cur].siz + tree[2 * cur + 1].siz;
}

void update(int cur, int l, int r, int x, int v)
{
    if(x < l || x > r || l > r)
        return;
    tree[cur].god.clear();
    if(l == r && l == x)
    {
        if(k == 1)
            tree[cur].ans = 1;
        else
            tree[cur].ans = INT_MAX;
        tree[cur].siz = 1;
        tree[cur].god.push_back(make_pair(v, 1));
        return;
    }

    int m = l + r >> 1;
    update(2 * cur, l, m, x, v);
    update(2 * cur + 1, m + 1, r, x, v);

    deque<pair<int, int> > deq;
    for(vector<pair<int, int> >::reverse_iterator it = tree[2 * cur].god.rbegin(); it != tree[2 * cur].god.rend(); it++)
    {
        if(cnt[it -> first] == 0)
            deq.push_front(*it);
        cnt[it -> first]++;
    }
    for(vector<pair<int, int> >::iterator it = tree[2 * cur + 1].god.begin(); it != tree[2 * cur + 1].god.end(); it++)
    {
        if(cnt1[it -> first] == 0)
            deq.push_back(make_pair(it -> first, it -> second + tree[2 * cur].siz));
        cnt1[it -> first]++;
    }
    tree[cur].ans = min(tree[2 * cur].ans, tree[2 * cur + 1].ans);
    int p = 0, q = 0, c = 0, lim = deq.size();
    for(; p < lim; p++)
    {
        while(q < lim && c < k)
        {
            if(cnt2[deq[q].first] == 0)
                c++;
            cnt2[deq[q].first]++;
            q++;
        }
        if(c == k)
            tree[cur].ans = min(tree[cur].ans, deq[q - 1].second - deq[p].second + 1);
        if(cnt2[deq[p].first]== 1)
            c--;
        cnt2[deq[p].first]--;
    }

    memset(cnt, 0, sizeof(cnt));
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));

    for(vector<pair<int, int> >::iterator it = tree[2 * cur].god.begin(); it != tree[2 * cur].god.end(); it++)
        cnt1[it -> first]++;
    for(vector<pair<int, int> >::iterator it = tree[2 * cur + 1].god.begin(); it != tree[2 * cur + 1].god.end(); it++)
        cnt1[it -> first]++;
    for(vector<pair<int, int> >::iterator it = tree[2 * cur].god.begin(); it != tree[2 * cur].god.end(); it++)
    {
        if(cnt2[it -> first] == 0 || cnt2[it -> first] == cnt1[it -> first] - 1)
            tree[cur].god.push_back(*it);
        cnt2[it -> first]++;
    }
    for(vector<pair<int, int> >::iterator it = tree[2 * cur + 1].god.begin(); it != tree[2 * cur + 1].god.end(); it++)
    {
        if(cnt2[it -> first] == 0 || cnt2[it -> first] == cnt1[it -> first] - 1)
            tree[cur].god.push_back(make_pair(it -> first, it -> second + tree[2 * cur].siz));
        cnt2[it -> first]++;
    }

    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));

    tree[cur].siz = tree[2 * cur].siz + tree[2 * cur + 1].siz;
}

int main()
{
    int q, x, v;
    cin>>n>>k>>q;
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    build(1, 1, n);
    while(q--)
    {
        scanf("%d %d", &x, &v);
        update(1, 1, n, x, v);
        a[x] = v;
        if(tree[1].ans != INT_MAX)
            printf("%d\n", tree[1].ans);
        else
            printf("-1\n");
    }
    return 0;
}
