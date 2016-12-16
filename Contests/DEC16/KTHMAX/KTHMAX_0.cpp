#include<bits/stdc++.h>
using namespace std;

map<int, vector<int> > god;
vector<pair<long long, int> > ans;
set<int> cover;

int main()
{
    int t, n, m;
    long long x;
    cin>>t;
    while(t--)
    {
        god.clear();
        ans.clear();
        cover.clear();
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            god[x].push_back(i);
        }
        long long z = 0;
        cover.insert(0);
        cover.insert(n + 1);
        for(map<int, vector<int> >::reverse_iterator it = god.rbegin(); it != god.rend(); it++)
        {
            int temp = it -> first;
            long long temp2 = 0;
            for(vector<int>::iterator it1 = (it -> second).begin(); it1 != (it -> second).end(); it1++)
            {
                int pos = (*it1);
                set<int>::iterator it2 = cover.upper_bound(pos);
                set<int>::iterator it3 = it2;
                it3--;
                temp2 += (1LL * ((*it2) - pos) * (pos - (*it3)));
                cover.insert(pos);
            }
            z += temp2;
            ans.push_back(make_pair(z, temp));
        }
        while(m--)
        {
            scanf("%lld", &x);
            long long l = 0, r = ans.size() - 1;
            while(l < r)
            {
                long long mid = l + r >> 1;
                if(ans[mid].first < x)
                    l = mid + 1;
                else
                    r = mid;
            }
            printf("%d\n", ans[l].second);
        }
    }
    return 0;
}
