#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

ll MOD = 1000003;
ll n,l,r,p;
ll f[1000010];

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

ll inverse(ll n)
{
    return (raise(n,MOD-2))%MOD;
}


ll util(ll n,ll r)
{
    ll i;
    f[0]=f[1]=1;
    for(i=2;i<=n;i++)f[i]=(i*f[i-1])%MOD;
    return (f[n]*(inverse(f[r])*inverse(f[n-r]))%MOD)%MOD;
}

ll cmb(ll n, ll r)
{
    if(r==0)return 1;
    if(n==0)return 0;
    ll n1,r1;
    n1=n%MOD;
    r1=r%MOD;
    if(r1>n1)return 0;
    return (cmb(n/MOD,r/MOD)*util(n1,r1))%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>l>>r;
        cout<<(cmb(n+r-l+1,n)-1+MOD)%MOD<<endl;
    }
    return 0;
}


// ^_^ \\
