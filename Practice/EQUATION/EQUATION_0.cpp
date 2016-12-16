#include<bits/stdc++.h>
using namespace std;

long long int nC3(long long int n)
{
    if(n<3)return 0;
    return (n*(n-1)*(n-2))/6;
}

int main()
{
    long long int t,n,a,b,c;
    long long int r=0,ra=0,rb=0,rc=0,rab=0,rac=0,rbc=0,rabc=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>c;
        r=nC3(n+3);
        ra=nC3(n+3-a-1);
        rb=nC3(n+3-b-1);
        rc=nC3(n+3-c-1);
        rab=nC3(n+3-a-b-2);
        rbc=nC3(n+3-b-c-2);
        rac=nC3(n+3-a-c-2);
        rabc=nC3(n+3-a-b-c-3);
        cout<<r-ra-rb-rc+rab+rbc+rac-rabc<<endl;
    }
    return 0;
}