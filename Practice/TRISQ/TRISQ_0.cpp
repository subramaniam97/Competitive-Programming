#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,b,r;
    cin>>t;
    while(t--)
    {
        r=0;
        scanf("%d",&b);
        for(int i=2;i<=b;i+=2)
        {
            r+=((b-i)>>1);
        }
        printf("%d\n",r);
    }
    return 0;
}