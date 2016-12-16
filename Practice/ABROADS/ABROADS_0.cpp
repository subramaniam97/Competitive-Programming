#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair

ll p[500001],s[500001],d[500001],op[500001],x[500001],y[500001],r[500001];
bool nbr[500001];
char qq[500001];

set<pair<ll,ll>,greater<pair<ll,ll> > > ss;

struct sub
{
    ll parent;
    ll rank;
}a[500001];

ll contain(ll i)
{
    if(a[i].parent!=i)
        a[i].parent=contain(a[i].parent);
    return a[i].parent;
}

void glue(ll x,ll y)
{
    ll xrt=contain(x);
    ll yrt=contain(y);
    if(xrt==yrt)return;
    ss.erase(mp(p[xrt],xrt));
    ss.erase(mp(p[yrt],yrt));

    if(a[xrt].rank<a[yrt].rank)
    {
        a[xrt].parent=yrt;
        p[yrt]+=p[xrt];
        ss.insert(mp(p[yrt],yrt));
    }
    else if(a[xrt].rank>a[yrt].rank)
    {
        a[yrt].parent=xrt;
        p[xrt]+=p[yrt];
        ss.insert(mp(p[xrt],xrt));
    }
    else
    {
        a[yrt].parent=xrt;
        a[xrt].rank++;
        p[xrt]+=p[yrt];
        ss.insert(mp(p[xrt],xrt));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,q,i,j,reg;
    cin>>n>>m>>q;
    for(i=1;i<=n;i++)
    {
        cin>>p[i];
        a[i].parent=i;
        a[i].rank=0;
    }
    for(i=1;i<=m;i++)
    {
        cin>>s[i]>>d[i];
        nbr[i]=true;
    }
    for(i=1;i<=q;i++)
    {
        cin>>qq[i];
        if(qq[i]=='D')
        {
            cin>>x[i];
            nbr[x[i]]=false;
        }
        else
        {
            cin>>x[i]>>y[i];
            op[i]=p[x[i]];
            p[x[i]]=y[i];
        }
    }
    for(i=1;i<=n;i++)
    {
        ss.insert(mp(p[i],i));
    }
    for(i=1;i<=m;i++)
    {
        if(nbr[i])
        {
            glue(s[i],d[i]);
        }
    }
    r[q]=(*ss.begin()).first;
    for(i=q;i>=1;i--)
    {
        if(qq[i]=='D')
        {
            glue(s[x[i]],d[x[i]]);
        }
        else
        {
            reg=contain(x[i]);
            ss.erase(mp(p[reg],reg));
            p[reg]-=y[i];
            p[reg]+=op[i];
            ss.insert(mp(p[reg],reg));
        }
        r[i-1]=(*ss.begin()).first;
    }
    for(i=1;i<=q;i++)
    {
        cout<<r[i]<<endl;
    }
    return 0;
}
