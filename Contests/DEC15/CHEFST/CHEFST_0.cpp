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


int main()
{
    ios_base::sync_with_stdio(0);
    ll t,k,n1,n2,m;
    cin>>t;
    while(t--)
    {
        cin>>n1>>n2>>m;
        k=(m*(m+1))/2;
        if(n1>n2)swap(n1,n2);
        if(k>=n1)cout<<n2-n1<<endl;
        else
        {
            n1=n1-k;
            n2=n2-k;
            cout<<n2+n1<<endl;
        }
    }
    return 0;
}


// ^_^ \\
