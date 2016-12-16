#include<bits/stdc++.h>
using namespace std;

int a[101][101];
int sp[101][101];
int sp1[101][101];
int n, m, k1, k2, r;
bool exists;
queue<pair<int, int> > q;

void update(int x, int y)
{
    for(int i = 0; i < k1; i++)
        for(int j = 0; j <= i; j++)
        {
            if((x - k1 + i >= 0) && (x - k1 + i < n) && (y + j >= 0) && (y + j < m) && (a[x - k1 + i][y + j] == 0))
            {
                if(sp[x - k1 + i][y + j] == -1)
                {
                    sp[x - k1 + i][y + j] = sp[x][y] + 1;
                    q.push(make_pair(x - k1 + i, y + j));
                }
            }
            if((x - k1 + i >= 0) && (x - k1 + i < n) && (y - j >= 0) && (y - j < m) && (a[x - k1 + i][y - j] == 0))
            {
                if(sp[x - k1 + i][y - j] == -1)
                {
                    sp[x - k1 + i][y - j] = sp[x][y] + 1;
                    q.push(make_pair(x - k1 + i, y - j));
                }
            }
        }
    for(int i = 0; i <= k1; i++)
        for(int j = 0; j <= i; j++)
        {
            if((x + k1 - i >= 0) && (x + k1 - i < n) && (y + j >= 0) && (y + j < m) && (a[x + k1 - i][y + j] == 0))
            {
                if(sp[x + k1 - i][y + j] == -1)
                {
                    sp[x + k1 - i][y + j] = sp[x][y] + 1;
                    q.push(make_pair(x + k1 - i, y + j));
                }
            }
            if((x + k1 - i >= 0) && (x + k1 - i < n) && (y - j >= 0) && (y - j < m) && (a[x + k1 - i][y - j] == 0))
            {
                if(sp[x + k1 - i][y - j] == -1)
                {
                    sp[x + k1 - i][y - j] = sp[x][y] + 1;
                    q.push(make_pair(x + k1 - i, y - j));
                }
            }
        }
}

void update1(int x, int y)
{
    for(int i = 0; i < k2; i++)
        for(int j = 0; j <= i; j++)
        {
            if((x - k2 + i >= 0) && (x - k2 + i < n) && (y + j >= 0) && (y + j < m) && (a[x - k2 + i][y + j] == 0))
            {
                if(sp1[x - k2 + i][y + j] == -1)
                {
                    sp1[x - k2 + i][y + j] = sp1[x][y] + 1;
                    q.push(make_pair(x - k2 + i, y + j));
                }
            }
            if((x - k2 + i >= 0) && (x - k2 + i < n) && (y - j >= 0) && (y - j < m) && (a[x - k2 + i][y - j] == 0))
            {
                if(sp1[x - k2 + i][y - j] == -1)
                {
                    sp1[x - k2 + i][y - j] = sp1[x][y] + 1;
                    q.push(make_pair(x - k2 + i, y - j));
                }
            }
        }
    for(int i = 0; i <= k2; i++)
        for(int j = 0; j <= i; j++)
        {
            if((x + k2 - i >= 0) && (x + k2 - i < n) && (y + j >= 0) && (y + j < m) && (a[x + k2 - i][y + j] == 0))
            {
                if(sp1[x + k2 - i][y + j] == -1)
                {
                    sp1[x + k2 - i][y + j] = sp1[x][y] + 1;
                    q.push(make_pair(x + k2 - i, y + j));
                }
            }
            if((x + k2 - i >= 0) && (x + k2 - i < n) && (y - j >= 0) && (y - j < m) && (a[x + k2 - i][y - j] == 0))
            {
                if(sp1[x + k2 - i][y - j] == -1)
                {
                    sp1[x + k2 - i][y - j] = sp1[x][y] + 1;
                    q.push(make_pair(x + k2 - i, y - j));
                }
            }
        }
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k1>>k2;
        exists = 0;
        r = 1e9;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d",&a[i][j]);
        memset(sp, -1, sizeof(sp));
        memset(sp1, -1, sizeof(sp1));
        sp[0][0] = 0;
        q.push(make_pair(0, 0));
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            update(p.first, p.second);
        }
        sp1[0][m - 1] = 0;
        q.push(make_pair(0, m - 1));
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            update1(p.first, p.second);
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(sp[i][j] == -1 || sp1[i][j] == -1)
                    continue;
                exists = 1;
                r = min(r, (int)max(sp[i][j], sp1[i][j]));
            }
        if(exists)
            cout<<r<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
