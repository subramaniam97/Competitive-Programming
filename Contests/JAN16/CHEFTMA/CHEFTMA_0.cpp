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
 
int n,k,m,a[100001];
multiset<int> b;
multiset<int>::iterator p;
ll r;
 
int main()
{
    ios_base::sync_with_stdio(0);
    int t,i,x;
    cin>>t;
    while(t--)
    {
        r=0;
        b.clear();
        cin>>n>>k>>m;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            cin>>x;
            a[i]-=x;
        }
        for(i=0;i<(m+k);i++)
        {
            cin>>x;
            b.insert(x);
        }
        for(i=0;i<n;i++)
        {
            p=b.lower_bound(a[i]);
            if(*p==a[i])
            {
                a[i]=0;
                b.erase(p);
            }
            else
            {
                if(p!=b.begin())
                {
                    p--;
                    a[i]-=*p;
                    b.erase(p);
                }
            }
            r+=a[i];
        }
 
        cout<<r<<endl;
    }
    return 0;
}
 
 
// ^_^ \\