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
int vtemp[1000001],htemp[1000001];
int vmax[1000001],hmax[1000001];
int a[1000001];
int maxi;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    int t,n,m,x;
    int r;
    cin>>t;
    maxi=0;
    while(t--)
    {
        r=0;
        cin>>n>>m;
        for(int i=0;i<=maxi;i++)
        {
            vcount[i].clear();
            hcount[i].clear();
            hmax[i]=0;
            vmax[i]=0;
        }
        maxi=0;
        for(int i=1;i<=(n*m);i++)
        {
            cin>>a[i];
            maxi=max(maxi,a[i]);
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
        for(int i=1;i<=maxi;i++)
        {
            p=vcount[i].rbegin();
            q=hcount[i].rbegin();
            if(p==vcount[i].rend())
            {
                if(q==hcount[i].rend())continue;
                r=max(r,(*q).first);
                continue;
            }
            if(q==hcount[i].rend())
            {
                if(p==vcount[i].rend())continue;
                r=max(r,(*p).first);
                continue;
            }
            while((*p).first==vmax[i])
            {
                done=0;
                q=hcount[i].rbegin();
                while((*q).first==hmax[i])
                {
                    if(a[((*q).second)+((*p).second)-1]!=i)
                    {
                        done=1;
                        r = max(r,(*p).first+(*q).first);
                        break;
                    }
                    r = max(r,(*p).first+(*q).first - 1);
                    q++;
                    if(q==hcount[i].rend())break;
                }
                if(done==1)break;
                p++;
                if(p==vcount[i].rend())break;
            }
        }
        cout<<r<<endl;
    }
    return 0;
}


// ^_^ \\
