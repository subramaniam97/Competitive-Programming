#include<bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a[5][5];
        int n = 3, m = 3;
        long long ans = 0;
        for(int i = 1; i <= n; i++)
        {
            long long temp = 0;
            for(int j = 1; j <= m; j++)
            {
                scanf("%lld", &a[i][j]);
                temp += a[i][j];
            }
            ans = max(ans, temp);
        }
        for(int i = 1; i <= n; i++)
        {
            long long temp = 0;
            for(int j = 1; j <= m; j++)
                temp += a[j][i];
            ans = max(ans, temp);
        }
        if(ans & 1)
            printf("%lld\n", ans);
        else if(ans == 0)
            printf("0\n");
        else
            printf("%lld\n", ans - 1);
    }
    return 0;
}
