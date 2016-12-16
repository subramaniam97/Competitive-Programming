#include<bits/stdc++.h>
using namespace std;

long long int n,m;

int main()
{
    int t;
    scanf(" %d", &t);
    while(t--)
    {
        scanf(" %lld %lld", &n, &m);
        if(n==1||m==1)
        {
            if((n==1&&m==2)||(n==2&&m==1))printf("Yes\n");
            else printf("No\n");
            continue;
        }
        if((n&1) && (m&1))
        {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
    }
    return 0;
}