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

ll a[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    ll i,t,n,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>a[0];
        r=a[0];
        for(i=1;i<n;i++)
        {
            cin>>a[i];
            r=__gcd(r,a[i]);
        }
        cout<<(r*n)<<endl;
    }
    return 0;
}


// ^_^ \\