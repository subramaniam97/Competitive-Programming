#include<bits/stdc++.h>
using namespace std;

long long ans;
int v[100005];
int xs[100005], xe[100005], ys[100005], ye[100005];
vector<pair<pair<int, int>, int> > vec, vec1;
pair<int, int> tree[100005];


void update(int i, int vv)
{
    for(; i < 100005; i += (i & (-i)))
        tree[i].first += vv;
}

int query(int i)
{
    int sum = 0;
    while(i)
    {
        sum += tree[i].first;
        i -= (i & (-i));
    }
    return sum;
}


int main()
{
    int n, x1, y1, x2, y2, r;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);

        if(y1 > y2)
            swap(y1, y2);
        if(x1 > x2)
            swap(x1, x2);

        xs[i] = x1;
        xe[i] = x2;
        ys[i] = y1;
        ye[i] = y2;

        if(x1 == x2)
        {
            vec.push_back(make_pair(make_pair(x1, 2), i));
            vec1.push_back(make_pair(make_pair(y1, 1), i));
            vec1.push_back(make_pair(make_pair(y2, 3), i));
        }
        else
        {
            vec.push_back(make_pair(make_pair(x1, 1), i));
            vec.push_back(make_pair(make_pair(x2, 3), i));
            vec1.push_back(make_pair(make_pair(y1, 2), i));
        }

    }

    sort(vec.begin(), vec.end());
    sort(vec1.begin(), vec1.end());

    for(int i = 0; i < 100005; i++)
    {
        tree[i].first = 0;
        tree[i].second = -1;
    }

    for(vector<pair<pair<int, int>, int> >::iterator it = vec.begin(); it != vec.end(); it++)
    {
        int id = (*it).second;

        if((*it).first.second == 1)
            update(ys[id], 1), tree[ys[id]].second = id;

        else if((*it).first.second == 3)
            update(ys[id], -1), tree[ys[id]].second = -1;

        else
        {
            y1 = ys[id];
            y2 = ye[id];
            r = 0;

            r = query(y2) - query(y1);
            if(tree[y2].second != -1 && ((xe[tree[y2].second] == xe[id]) || (xs[tree[y2].second] == xe[id])))
                r--;
            if(tree[y1].second != -1 && ((xe[tree[y1].second] != xe[id]) && (xs[tree[y1].second] != xe[id])))
                r++;

            ans += r;
            v[id] = r;
        }
    }

    for(int i = 0; i < 100005; i++)
    {
        tree[i].first = 0;
        tree[i].second = -1;
    }

    for(vector<pair<pair<int, int>, int> >::iterator it = vec1.begin(); it != vec1.end(); it++)
    {
        int id = (*it).second;

        if((*it).first.second == 1)
            update(xs[id], 1), tree[xs[id]].second = id;

        else if((*it).first.second == 3)
            update(xs[id], -1), tree[xs[id]].second = -1;

        else
        {
            x1 = xs[id];
            x2 = xe[id];
            r = 0;

            r = query(x2) - query(x1);
            if(tree[x2].second != -1 && ((ye[tree[x2].second] == ye[id]) || (ys[tree[x2].second] == ye[id])))
                r--;
            if(tree[x1].second != -1 && ((ye[tree[x1].second] != ye[id]) && (ys[tree[x1].second] != ye[id])))
                r++;
            v[id] = r;
        }
    }

    printf("%lld\n", ans);
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    return 0;
}
