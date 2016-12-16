#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100002];
bool visited[100002];
long long int temp;

void dfs(int source)
{
    temp++;
    visited[source] = 1;
    for(vector<int>::iterator p = adj[source].begin(); p != adj[source].end(); p++)
    {
        if(!visited[*p])
        {
            dfs(*p);
        }
    }
}

int main()
{
    int t,n,m,x,y,r;
    long long int w;
    scanf(" %d",&t);
    while(t--)
    {
        r = 0;
        w = 1;
        for(int i = 0; i < 100002; i++)
        {
            visited[i] = 0;
            adj[i].clear();
        }
        scanf(" %d %d",&n,&m);
        for(int i = 0; i < m; i++)
        {
            scanf(" %d %d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                r++;
                temp = 0;
                dfs(i);
                w = (w * temp) % 1000000007;
            }
        }
        printf("%d %d\n",r,w);
    }
    return 0;
}
