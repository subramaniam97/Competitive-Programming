#include<bits/stdc++.h>
using namespace std;

int a[200005], x, y, n, w;
vector<long long> sl, sr, el, er;

int next(int i)
{
    int r = (i + 1) % n;
    if(r == 0)
        return n;
    return r;
}

int prev(int i)
{
    int r = (i - 1) % n;
    if(r == 0)
        return n;
    return r;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sl.clear();
        sr.clear();
        el.clear();
        er.clear();
        long long ans, ls = 0, rs = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", a + i);
        scanf("%d %d", &x, &y);

        int i = x;
        long long h = 0;
        sr.push_back(h);
        while(i != y)
        {
            h += a[i];
            sr.push_back(h);
            i = next(i);
        }
        rs = h;
        i = x;
        h = 0;
        sl.push_back(h);
        while(i != y)
        {
            h += a[prev(i)];
            sl.push_back(h);
            i = prev(i);
        }
        ls = h;
        i = y;
        h = 0;
        er.push_back(h);
        while(i != x)
        {
            h += a[i];
            er.push_back(h);
            i = next(i);
        }

        i = y;
        h = 0;
        el.push_back(h);
        while(i != x)
        {
            h += a[prev(i)];
            el.push_back(h);
            i = prev(i);
        }

        for(int i = 1; i < sr.size(); i++)
            sr[i] = min(sr[i], sr[i - 1]);
        for(int i = 1; i < sl.size(); i++)
            sl[i] = min(sl[i], sl[i - 1]);
        for(int i = 1; i < er.size(); i++)
            er[i] = min(er[i], er[i - 1]);
        for(int i = 1; i < el.size(); i++)
            el[i] = min(el[i], el[i - 1]);

        long long r1 = 0, r2 = 0;

        for(int i = 0; i < sr.size(); i++)
            r1 = min(r1, el[el.size() - 1 - i] + sr[i]);
        for(int i = 0; i < er.size(); i++)
            r2 = min(r2, er[er.size() - 1 - i] + sl[i]);

        ans = min(ls + r1 * 2LL, rs + r2 * 2LL);

        printf("%lld\n", ans);
    }
    return 0;
}
