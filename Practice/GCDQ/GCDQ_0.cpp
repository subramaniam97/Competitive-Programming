#include<bits/stdc++.h>
using namespace std;
#define N 100001

int p[100002],s[100002],n;

void preprocess(int *a)
{
    int i;
    for(i=1;i<=n;i++)
    {
        p[i]=__gcd(a[i],p[i-1]);
        s[n-i+1]=__gcd(a[n-i+1],s[n-i+2]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t,q,i,a[100002],l,r;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(i=1;i<=n;i++)cin>>a[i];
        p[0]=0;
        s[n+1]=0;
        preprocess(a);
        while(q--)
        {
            cin>>l>>r;
            cout<<__gcd(p[l-1],s[r+1])<<endl;
        }
    }
    return 0;
}