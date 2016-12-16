#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int i=0,j;
    ll n,a[100005],r=0,x,c=0,s;
    cin>>n;
    while(n--)
    {
        cin>>a[i];
        if(a[i]>=0)i--;
        i++;
    }
    sort(a,a+i);
    cin>>x;
    for(j=i-1;j>=0;j--)
    {
        a[j]+=c;
        if(a[j]>=0)continue;
        if((j+1)>=x)
        {
            s=-a[j];
            c+=s;
            r+=(s*x);
        }
        else
        {
            r+=fabs(a[j]);
        }
    }
    
    
    cout<<r;
    return 0;
}
