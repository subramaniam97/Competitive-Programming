#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> adj[10];
vector<int> r;
string s;
int f;

void bfs(int source)
{
    int n,j,ft;
    vector<int>::iterator i;
    r.pb(source);
    for(j=1;j<s.length();j++)
    {
        ft=0;
        for(i=adj[r.back()].begin();i!=adj[r.back()].end();i++)
        {
                if(*i==s[j]-65||*i==s[j]-60)
                {
                    r.pb(*i);
                    ft=1;
                    break;
                }
        }
        if(!ft){f=0; return;}
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    adj[0].pb(1), adj[0].pb(4), adj[0].pb(5);
    adj[2].pb(1), adj[2].pb(3), adj[2].pb(7);
    adj[3].pb(4), adj[3].pb(2), adj[3].pb(8);
    adj[4].pb(9), adj[4].pb(3), adj[4].pb(0);
    adj[5].pb(0), adj[5].pb(8), adj[5].pb(7);
    adj[6].pb(9), adj[6].pb(8), adj[6].pb(1);
    adj[7].pb(5), adj[7].pb(9), adj[7].pb(2);
    adj[8].pb(5), adj[8].pb(6), adj[8].pb(3);
    adj[9].pb(7), adj[9].pb(4), adj[9].pb(6);
    adj[1].pb(0), adj[1].pb(6), adj[1].pb(2);
    int t,i;
    cin>>t;
    while(t--)
    {
        r.clear();
        cin>>s;
        f=1;
        bfs(s[0]-65);
        if(!f)
        {
            f=1;
            r.clear();
            bfs(s[0]-60);
        }
        if(!f)cout<<"-1\n";
        else
        {
            for(i=0;i<r.size();i++)cout<<r[i];
            cout<<endl;
        }
    }
    return 0;
}


// ^_^ \\
