#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,n,a,b,r,p,q,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        p=q=0;
        x=a,y=b;
        while(x)
        {
            if(x&1)p++;
            x>>=1;
        }
        while(y)
        {
            if(y&1)q++;
            y>>=1;
        }
        if((p+q)==n)r=pow(2,n)-1;
        else
        {
            r=pow(2,n)-pow(2,abs(n-(p+q)));
        }
        cout<<r<<endl;
    }
    return 0;
}