#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k,a[100],i,s,ts;
    cin>>t;
    while(t--)
    {
        ts=0;
        cin>>n>>k;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            ts+=a[i];
        }
        sort(a,a+n);
        if(k<=(n/2))
        {
            s=0;
            for(i=0;i<k;i++)
            {
               s+=a[i]; 
            }
            cout<<abs(ts-2*s)<<endl;
        }
        else
        {
           s=0;
           for(i=n-1;i>=(n-k);i--)
           {
                s+=a[i];   
           }
           cout<<abs(ts-2*s)<<endl;
        }
    }
    return 0;
}