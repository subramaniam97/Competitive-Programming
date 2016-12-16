#include<bits/stdc++.h>
using namespace std;

bool exists[1002][1002];
vector<int> adj[1002];
int col[1002];
bool flag;

void bipartite(int cur, int c)
{
    if(col[cur] != -1)
    {
        if(col[cur] != c)
            flag = 0;
        return;
    }
    col[cur] = c;
    for(vector<int>::iterator it = adj[cur].begin(); it != adj[cur].end(); it++)
        bipartite(*it, !c);
}

int main()
{
    int t, n, x, y, m;
    cin>>t;
    while(t--)
    {
        flag = 1;
        for(int i = 0; i <= 1000; i++)
            adj[i].clear();
        memset(col, -1, sizeof(col));
        memset(exists, 0, sizeof(exists));
        scanf(" %d %d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            exists[x][y] = 1;
            exists[y][x] = 1;
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i != j && !exists[i][j])
                    adj[i].push_back(j), adj[j].push_back(i);

        for(int i = 1; i <= n; i++)
        {
            if(col[i] == -1)
                bipartite(i, 0);
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
