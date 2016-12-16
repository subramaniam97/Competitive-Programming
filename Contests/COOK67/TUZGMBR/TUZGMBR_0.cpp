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
    //freopen("input.txt","r",stdin);
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        n--;
        m--;
        if((n%4==0&&m%3==0)||(n%4==1&&m%3==1)||(n%4==2&&m%3==2))
        {
            cout<<"Vanya\n";
        }
        else
        {
            cout<<"Tuzik\n";
        }
    }
    return 0;
}


// ^_^ \\