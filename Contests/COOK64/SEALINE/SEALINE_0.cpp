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

ll a[101];

int main()
{
    ios_base::sync_with_stdio(0);
    ll i,t,n,r,m,j,k,x;
    cin>>t;
    while(t--)
    {
        m=0;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(x==0)
            {
                for(j=i;j>1;j--)a[j]=a[j-1];
                a[1]=i;
            }
            else if(a[i-1]!=x)
            {
                for(j=1;j<i;j++)
                {
                    if(a[j]==x)break;
                }
                m+=min(i-j-1,j);
                for(k=i;k>j+1;k--)a[k]=a[k-1];
                a[k]=i;
            }
            else a[i]=i;
        }
        cout<<m<<endl;
    }
    return 0;
}


// ^_^ \\
