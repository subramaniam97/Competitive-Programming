#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll MOD = 1000000007;

bool look_up[21];

unsigned ll raise(unsigned ll b, unsigned ll exp)
{
    unsigned ll r=1;
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
    ll t,n,k,i;
    unsigned ll cn,r;
    cin>>t;
    while(t--)
    {
        k=0;
        cn=0;
        cin>>n;
        while(n)
        {
            look_up[k++]=n&1;
            n>>=1;
        }
        for(i=k-1;i>=0;i--)
        {
            cn=look_up[i]+10*cn;
        }
        r=raise(2,cn);
        r=(r*r)%MOD;
        cout<<r<<endl;
    }
}