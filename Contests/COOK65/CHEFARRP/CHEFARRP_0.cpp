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

ll a[51],pp[2000],ps[2000],sp[2000],ss[2000];

int main()
{
    ios_base::sync_with_stdio(0);
    ll t,n,i,r,j,w,x,y,z,s,p,s1,p1;
    cin>>t;
    while(t--)
    {
        s=w=y=0;
        p=x=z=1;
        r=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            s+=a[i];
            p*=a[i];
        }
        for(i=0;i<n;i++)
        {
            w += a[i];
            x *= a[i];
            y += a[n-i-1];
            z *= a[n-i-1];
            pp[i]=x;
            ps[i]=w;
            sp[n-i-1]=z;
            ss[n-i-1]=y;
            //cout<<x<<" "<<w<<" "<<z<<" "<<y<<endl;
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                s1 = (s - (ss[j]+ps[i]))+a[j]+a[i];
                p1 = (p/(sp[j]*pp[i]))*a[j]*a[i];
               // cout<<s1<<" "<<p1<<endl;
                if(s1==p1)r++;
            }
        }
        cout<<r+n<<endl;
    }
    return 0;
}


// ^_^ \\
