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
    int t,n,d;
    cin>>t;
    while(t--)
    {
        cin>>d>>n;
        for(int i=0;i<d;i++)
        {
            n = (n*(n+1))/2;
        }
        cout<<n<<endl;
    }
    return 0;
}


// ^_^ \\