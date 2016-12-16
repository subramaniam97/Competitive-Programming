#include<bits/stdc++.h>
using namespace std;

char a[502][502];
bool dp[502][502];
bool hdp[502][502];
bool d[502];

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        int r = 0;
        cin>>n;
        memset(dp,0,sizeof(dp));
        memset(hdp,0,sizeof(hdp));
        memset(d,0,sizeof(d));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf(" %c",&a[i][j]);
        for(int i = n; i >= 1; i--)
        {
            for(int j = 1; j <= n; j++)
            {
                if(a[i][j] == '#')
                    dp[i][j] = 1;
                else
                    dp[i][j] |= dp[i + 1][j];
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(a[i][j] == '#')
                    hdp[i][j] = 1;
                else
                    hdp[i][j] |= hdp[i][j - 1];
            }
        }


        for(int j = n; j >= 1; j--)
        {
            for(int i = 1; i <= n; i++)
                if(!d[i] && dp[i][j] == 0 && hdp[i][j] == 0)
                {
                    r++, d[i] = 1;
                    break;
                }
        }

        printf("%d\n",r);
    }
    return 0;
}
