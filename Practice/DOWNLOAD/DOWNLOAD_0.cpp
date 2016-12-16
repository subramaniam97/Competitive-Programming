#include<bits/stdc++.h>
using namespace std;

int q[5005][22];
int ans[5005], bit[300005], startIndex[300005];
vector<pair<pair<int, int>, pair<int, int> > > god;
int n;
/*
god[j][m][i][k]
If i = 1 then j is the start of interval k
If i = 3 then j is the end of interval k
If i = 2 then j is a query point belonging to query k having index m in the sorted order
*/

void update(int i, int v)
{
    while(i < 300005)
    {
        bit[i] += v;
        i += (i & (-i));
    }
}

int query(int i)
{
    int ans = 0;
    while(i)
    {
        ans += bit[i];
        i -= (i & (-i));
    }
    return ans;
}



int main()
{
    int qu, k, x, y;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &x, &y);
        god.push_back(make_pair(make_pair(x, -1), make_pair(1, i)));
        god.push_back(make_pair(make_pair(y, INT_MAX), make_pair(3, i)));
    }
    cin>>qu;
    for(int i = 1; i <= qu; i++)
    {
        scanf("%d", &k);
        for(int j = 1; j <= k; j++)
            scanf("%d", &q[i][j]);
        sort(q[i] + 1, q[i] + 1 + k);
        for(int j = 1; j <= k; j++)
            god.push_back(make_pair(make_pair(q[i][j], j), make_pair(2, i)));
    }

    sort(god.begin(), god.end());
    int compressedValue = 1;

    for(int i = 0; i < god.size(); i++)
    {
        if(i > 0 && god[i].first.first != god[i - 1].first.first)
            compressedValue++;
        if(god[i].second.first == 1)
        {
            startIndex[god[i].second.second] = compressedValue;
            update(compressedValue, 1);
        }
        else if(god[i].second.first == 3)
        {
            update(startIndex[god[i].second.second], -1);
        }
        else
        {
            q[god[i].second.second][god[i].first.second] = compressedValue;
            ans[god[i].second.second] += query(compressedValue) - query(q[god[i].second.second][god[i].first.second - 1]);
        }
    }

    for(int i = 1; i <= qu; i++)
        printf("%d\n", ans[i]);

    return 0;
}
