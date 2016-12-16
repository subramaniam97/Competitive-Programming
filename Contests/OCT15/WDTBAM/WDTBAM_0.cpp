#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    char a[1001],b[1001];
    int t,n,c[1001],i,p,l,r;
    cin>>t;
    while(t--)
    {
        p=0;
        cin>>n;
        for(i=0;i<n;i++)cin>>a[i];
        for(i=0;i<n;i++)cin>>b[i];
        for(i=0;i<n+1;i++)cin>>c[i];
        for(i=0;i<n;i++)
        {
            if(a[i]==b[i])p++;
        }
        if(p==n){l=1; r=c[n];}
        else if(p==0)r=c[0];
        else
        {
            for(i=1;i<=p;i++)
            {
                if(c[0]<c[i])break;
            }
            if(i==(p+1))r=c[0];
            else
            {
                sort(c+1,c+p+1);
                r=c[p];
            }
        }
        cout<<r<<endl;

    }
    return 0;
}
