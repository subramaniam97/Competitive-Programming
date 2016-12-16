#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int a[100001],dp[100001];

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        dp[n-1] = 1;
        for(int i = n - 2; i >= 0; i--)
        {
            if((a[i] > 0 && a[i+1] < 0)||(a[i] < 0 && a[i+1] > 0))
            {
                dp[i] = dp[i+1] + 1;
            }
            else
            {
                dp[i] =  1;
            }
        }
        for(int i = 0; i < n; i++)
        {
            printf("%d ",dp[i]);
        }
        printf("\n");
    }
    return 0;
}