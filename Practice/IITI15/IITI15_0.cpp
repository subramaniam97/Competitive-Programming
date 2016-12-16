#include<bits/stdc++.h>
using namespace std;

int a[20002], n;
map<int, int> m;
long long inv, ans[20002];
int tree[20002];
vector<pair<pair<pair<int, int>, int>, int> > z;

void update(int index, int val)
{
    while(index <= n)
    {
        tree[index] += val;
        index += index & (-index);
    }
}

long long query(int index)
{
    long long sum = 0;
    while(index)
    {
        sum += tree[index];
        index -= (index & (-index));
    }
    return sum;
}

int main()
{
    int l, r, qu, k = 1;
    cin>>n;
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i), m[a[i]];
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        it -> second = k++;
    for(int i = 1; i <= n; i++)
        a[i] = m[a[i]];
    int p = 1, q = 1;
    cin>>qu;
    int x = sqrt(n);
    for(int i = 1; i <= qu; i++)
    {
        scanf("%d %d", &l, &r);
        z.push_back(make_pair(make_pair(make_pair((l - 1) / x + 1, r), l), i));
    }
    sort(z.begin(), z.end());
    update(a[1], 1);
    for(int i = 0; i < z.size(); i++)
    {
        l = z[i].first.second;
        r = z[i].first.first.second;
        while(p > l)
        {
            p--;
            update(a[p], 1);
            inv += query(a[p] - 1);
        }
        while(p < l)
        {
            inv -= query(a[p] - 1);
            update(a[p], -1);
            p++;
        }
        while(q < r)
        {
            q++;
            inv += ((q - p) - query(a[q]));
            update(a[q], 1);
        }
        while(q > r)
        {
            update(a[q], -1);
            inv -= ((q - p) - query(a[q]));
            q--;
        }
        ans[z[i].second] = inv;
    }
    for(int i = 1; i <= qu; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
