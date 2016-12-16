#include<bits/stdc++.h>
#define ll long long INT_MAX
using namespace std;

long long int a[51],foo[1000001];

int main()
{
    int n,i,k,q,r;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        r=a[i];
        foo[r]++;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<r)r=a[j];
            foo[r]++;
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&k);
        printf("%lld\n",foo[k]);
    }
    return 0;
}
