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

ll a[100010],x,s[100010],pow2[100002];
ll r;

void pre()
{
    ll i;
    pow2[0]=1;
    pow2[1]=2;
    for(i=2;i<100002;i++)pow2[i]=(pow2[i-1]*(ll)2)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll t,n,i;
    pre();
    cin>>t;
    while(t--)
    {
        r=0;
        cin>>n;
        for(i=0;i<=n;i++)
        {
            cin>>a[i];
            if(i>=2)
            {
                x=(pow2[n-i]*a[i])%MOD;
                s[i]=(s[i-1]+x)%MOD;
            }
        }
        for(i=1;i<n;i++)
        {
            r=(r+(((pow2[i]*a[i])%MOD)*(s[n]-s[i]))%MOD)%MOD;
            r=(r+(((pow2[i]*a[n-i+1])%MOD)*a[0])%MOD)%MOD;
        }
        r=(r+(((pow2[n]*a[1])%MOD)*a[0])%MOD)%MOD;

        cout<<r<<endl;
    }
    return 0;
}


// ^_^ \\
