#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int p,t,n,i,a[100005];
    long long int r;
    cin>>t;
    while(t--)
    {
        int b[100005];
        p=1;
        r=0;
        cin>>n;
        b[0]=1;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(!p)
            {
                if(a[i]>=a[i-1])b[i]=1+b[i-1];
                else b[i]=1;
            }
            p=0;
            r+=b[i];
        }
        cout<<r<<endl;
        
    }
    return 0;
}
