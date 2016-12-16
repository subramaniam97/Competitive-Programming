#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t,n,x,y;
    scanf("%d",&t);
    while(t--)
    {
        x = 0;
        scanf("%d",&n);
        for(int i = 0 ; i < n; i++)
        {
            scanf("%d",&y);
            x ^= y;
        }
        if((n&1) && (x!=0)) printf("Second\n");
        else printf("First\n");
    }
    return 0;
}