#include<bits/stdc++.h>
using namespace std;

int sp[100005];
vector<pair<int, int> > adj[100005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

void dijkstra(int source)
{
    q.push(make_pair(0, source));
    sp[source] = 0;

    while(!q.empty())
    {
        pair<int, int> x = q.top();
        q.pop();
        int dist = x.first;
        int v = x.second;

        if(dist == sp[v])
        {
            for(vector<pair<int, int> >::iterator it = adj[v].begin(); it != adj[v].end(); it++)
            {
                if(sp[it -> first] > sp[v] + it -> second)
                {
                    sp[it -> first] = sp[v] + it -> second;
                    q.push(make_pair(sp[it -> first], it -> first));
                }
            }
        }
    }
}

int main()
{
    for(int i = 0; i < 100005; i++)
        sp[i] = INT_MAX;
    int n, m;
    cin>>n>>m;
    while(m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(make_pair(b, 0));
        adj[b].push_back(make_pair(a, 1));
    }
    dijkstra(1);
    if(sp[n] != INT_MAX)
        cout<<sp[n]<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}
