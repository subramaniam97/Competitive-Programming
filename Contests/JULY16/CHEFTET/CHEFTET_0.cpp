#include<bits/stdc++.h>
using namespace std;

long long int a[10005], b[10005];
bool used[10005];
int n;

bool ok(long long int s)
{
    for(int i = 1; i <= n; i++)
    {
        int req = s - a[i];
        bool flag = 0;
        if(req < 0)
            return 0;
        if(req == 0)
            continue;
        vector<pair<int,int> > tmp;
        for(int j = i - 1; j <= i + 1; j++)
        {
            if(used[j])
                continue;
            tmp.push_back(make_pair(b[j], j));
        }
        while(tmp.size() != 3)
            tmp.push_back(make_pair(0, -1));
        if(tmp[0].first + tmp[1].first + tmp[2].first == req)
        {
            if(tmp[0].second != -1)
                used[tmp[0].second] = 1;
            if(tmp[1].second != -1)
                used[tmp[1].second] = 1;
            if(tmp[2].second != -1)
                used[tmp[2].second] = 1;
        }
        else if(tmp[0].first + tmp[1].first == req)
        {
            if(tmp[0].second != -1)
                used[tmp[0].second] = 1;
            if(tmp[1].second != -1)
                used[tmp[1].second] = 1;
        }
        else if(tmp[0].first + tmp[2].first == req)
        {
            if(tmp[0].second != -1)
                used[tmp[0].second] = 1;
            if(tmp[2].second != -1)
                used[tmp[2].second] = 1;
        }
        else if(tmp[2].first + tmp[1].first == req)
        {
            if(tmp[2].second != -1)
                used[tmp[2].second] = 1;
            if(tmp[1].second != -1)
                used[tmp[1].second] = 1;
        }
        else if(tmp[0].first == req)
        {
            if(tmp[0].second != -1)
                used[tmp[0].second] = 1;
        }
        else if(tmp[1].first == req)
        {
            if(tmp[1].second != -1)
                used[tmp[1].second] = 1;
        }
        else if(tmp[2].first == req)
        {
            if(tmp[2].second != -1)
                used[tmp[2].second] = 1;
        }
        else
        {
            return 0;
        }
    }
    for(int i = 1; i <= n; i++)
            if(used[i] == 0)
                return 0;
    return 1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long int x = 0, y = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0 ,sizeof(b));
        for(int i = 1; i <= n; i++)
            scanf("%lld", b + i), x += b[i];
        for(int i = 1; i <= n; i++)
            scanf("%lld", a + i), y += a[i];
        memset(used, 0, sizeof(used));
        if(ok((x + y) / n))
            cout<<(x + y) / n<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
