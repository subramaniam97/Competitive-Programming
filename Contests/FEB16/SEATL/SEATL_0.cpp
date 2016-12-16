#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

ll MOD = 1000000007;

ll raise(ll b, ll exp)
{
    ll r=1;
    while(exp)
    {
        if(exp&1)r=(r*b)%MOD;
        b=(b*b)%MOD;
        exp>>=1;
    }
    return r;
}

vector<pair<int,int> > vcount[1000001],hcount[1000001];
vector<pair<int,int> >::reverse_iterator p,q;
map<int,int> h;
map<int,int>::iterator g;
int vtemp[1000001],htemp[1000001];
int vmax[1000001],hmax[1000001];
int a[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    int t,n,m,x,k;
    int r;
    cin>>t;
    while(t--)
    {
        r=0;
        k=1;
        cin>>n>>m;
        for(g=h.begin();g!=h.end();g++)
        {
            vcount[(*g).first].clear();
            hcount[(*g).first].clear();
            hmax[(*g).first]=0;
            vmax[(*g).first]=0;
        }
        h.clear();
        for(int i=1;i<=(n*m);i++)
        {
            cin>>a[i];
            if(h[a[i]]==0)h[a[i]]=k++;
        }
        for(int i=1;i<=(n*m);i+=m)
        {
            for(int j=i;j<(i+m);j++)
            {
                htemp[a[j]]=0;
            }
            for(int j=i;j<(i+m);j++)
            {
                htemp[a[j]]++;
                if(htemp[a[j]]>=hmax[a[j]])
                {
                    hcount[a[j]].pb(mp(htemp[a[j]],i));
                    hmax[a[j]]=htemp[a[j]];
                }
            }
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=i;j<=(n*m);j+=m)
            {
                vtemp[a[j]]=0;
            }
            for(int j=i;j<=(n*m);j+=m)
            {
                vtemp[a[j]]++;
                if(vtemp[a[j]]>=vmax[a[j]])
                {
                    vcount[a[j]].pb(mp(vtemp[a[j]],i));
                    vmax[a[j]]=vtemp[a[j]];
                }
            }
        }
        bool done=0;
        for(g=h.begin();g!=h.end();g++)
        {
            p=vcount[(*g).first].rbegin();
            q=hcount[(*g).first].rbegin();
            if(p==vcount[(*g).first].rend())
            {
                if(q==hcount[(*g).first].rend())continue;
                r=max(r,(*q).first);
                continue;
            }
            if(q==hcount[(*g).first].rend())
            {
                if(p==vcount[(*g).first].rend())continue;
                r=max(r,(*p).first);
                continue;
            }
            while((*p).first==vmax[(*g).first])
            {
                done=0;
                q=hcount[(*g).first].rbegin();
                while((*q).first==hmax[(*g).first])
                {
                    if(a[((*q).second)+((*p).second)-1]!=(*g).first)
                    {
                        done=1;
                        r = max(r,(*p).first+(*q).first);
                        break;
                    }
                    r = max(r,(*p).first+(*q).first - 1);
                    q++;
                    if(q==hcount[(*g).first].rend())break;
                }
                if(done==1)break;
                p++;
                if(p==vcount[(*g).first].rend())break;
            }
        }
        cout<<r<<endl;
    }
    return 0;
}


// ^_^ \\
