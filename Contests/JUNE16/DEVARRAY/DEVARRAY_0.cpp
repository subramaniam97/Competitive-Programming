#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,mi = INT_MAX,ma = 0,a,q;
    cin>>n>>q;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a);
        mi = min(mi,a);
        ma = max(ma,a);
    }
    while(q--)
    {
        scanf("%d",&t);
        if(ma >= t && mi <= t)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
