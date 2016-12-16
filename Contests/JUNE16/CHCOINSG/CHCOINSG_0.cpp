#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        if(n % 6)
            printf("Chef\n");
        else
            printf("Misha\n");
    }
    return 0;
}
