#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

ll MOD = 1000000007;
vector<pair<int,int> >p;
bool c[100002];
bool r[100002];

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


int main()
{
    ios_base::sync_with_stdio(0);
    int i,n,q,x,y,par=0,d;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    	cin>>x>>y;
    	if((y-x+1)&1)r[i]=1;
    	p.pb(mp(x,y));
    	c[x]^=1;
    	c[y+1]^=1;
    	par^=r[i];
    }
    for(i=2;i<=n;i++)
    {
    	c[i]^=c[i-1];
    }
    cin>>q;
    while(q--)
    {
    	cin>>x>>y;
    	d=0;
    	if(p[x-1].first<=y&&y<=p[x-1].second)d=1;
    	
    	if(par^c[y]^r[x]^d)cout<<"O\n";
    	else cout<<"E\n";
    }
    return 0;
}


// ^_^ \\