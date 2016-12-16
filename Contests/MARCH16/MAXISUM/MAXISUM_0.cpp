#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll a[100001];

int main()
{
    int t,n;
    ll k,r,m,b;
    scanf("%d",&t);
    while(t--)
    {
        r=0;
        m=0;
        scanf("%d %lld",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&b);
            r += a[i]*b;
            m = max(m,abs(b));
        }
        r += k*m;
        printf("%lld\n",r);
    }
    return 0;
}
