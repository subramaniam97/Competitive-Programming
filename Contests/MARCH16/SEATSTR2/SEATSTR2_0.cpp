#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll MOD = 1000000007;
ll f[27];
ll fac[100001];
ll ifac[100001];
ll inv2,inv6;

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

ll inv(ll n)
{
    return raise(n,MOD-2);
}

void pre()
{
    inv2=inv(2);
    inv6=inv(6);
    fac[0]=fac[1]=1;
    ifac[0]=ifac[1]=1;
    for(ll i=2;i<=100000;i++)
    {
        fac[i]=(fac[i-1]*i)%MOD;
        ifac[i]=(ifac[i-1]*inv(i))%MOD;
    }
}

ll nC2(ll n)
{
    if(n<2)return 0;
    if(n==2)return 1;
    return (((n*(n-1))%MOD)*inv2)%MOD;
}

ll nC3(ll n)
{
    if(n<3)return 0;
    if(n==3)return 1;
    return (((((n*(n-1))%MOD)*(n-2))%MOD)*inv6)%MOD;
}

int main()
{
    string s;
    int t;
    ll m,n,r,r1,r2,over;
    pre();
    cin>>t;
    while(t--)
    {
        r = 0;
        m = 1;
        memset(f,0,sizeof(f));
        cin>>s;
        n = s.length();
        for(int i=0;i<n;i++)
        {
            f[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            m = (m*ifac[f[i]])%MOD;
        }
        m = (m*fac[n])%MOD;
        r += nC2(n);
        for(int i=0;i<26;i++)
        {
            r = (r - nC2(f[i]) + MOD)%MOD;
        }
        r = (r*m)%MOD;
        r1 = nC3(n);
        for(int i=0;i<26;i++)
        {
            r1 = (r1 - nC3(f[i]) + MOD)%MOD;
        }
        for(int i=0;i<26;i++)
        {
            r1 = (r1 - ((nC2(f[i])*(n - f[i]))%MOD) + MOD)%MOD;
        }
        r1 = (((r1*m)%MOD)*2)%MOD;
        r = (r+r1)%MOD;
        r2 = nC2(n);
        for(int i=0;i<26;i++)
        {
            r2 = (r2 - nC2(f[i]) + MOD)%MOD;
        }
        r1 = (r2*r2)%MOD;
        r1 = (r1 - r2 + MOD)%MOD;
        for(int i=0;i<26;i++)
        {
            over = f[i];
            while(over)
            {
                r1 = (r1 - (((n-f[i])*(n-f[i]-1))%MOD) + MOD)%MOD;
                over--;
            }
        }
        r1 = (r1*inv2)%MOD;
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                r1 = (r1 - ((nC2(f[i])*nC2(f[j]))%MOD) + MOD)%MOD;
            }
        }
        r1 = (r1*m)%MOD;
        r = (r + r1)%MOD;
        cout<<(((2*nC2(m))%MOD) - r + MOD)%MOD<<endl;
    }
}
