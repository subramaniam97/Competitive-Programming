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
    int t,n,n1,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n>=1&&n<=6)
        {
            cout<<"-1\n";
            continue;
        }
        cout<<n<<endl;
        n1=n;
        if(!(n1&1))n1--;
        for(i=1;i<(n1/2);i++)
        {
            cout<<i<<" "<<i+1<<endl;
        }
        cout<<i<<" "<<i+1<<endl;
        cout<<i<<" "<<i+2<<endl;
        if(!(n&1))cout<<i<<" "<<n<<endl;
        for(i+=2;i<n1;i++)
        {
            cout<<i<<" "<<i+1<<endl;
        }
        cout<<n1<<" 1"<<endl;
        cout<<(n1/2)-1<<endl;
    }
    return 0;
}


// ^_^ \\
