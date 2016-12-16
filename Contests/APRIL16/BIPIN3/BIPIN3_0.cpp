#include<bits/stdc++.h>
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


int main()
{
    ll n,k;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cout<<(k*raise(k-1,n-1))%MOD<<endl;
    }
    return 0;
}
