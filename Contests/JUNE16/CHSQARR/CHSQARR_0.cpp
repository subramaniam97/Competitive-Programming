#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];
int p[1001][1001];
int dp[1001][1001][2][2];

int mmax(int a,int b,int c,int d,int e)
{
    return max(a,max(b,max(c,max(d,e))));
}

int main()
{
    int n,m,a,b,r,q;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d",&t[i][j]);
            if(i != 0 && j != 0)
                p[i][j] = t[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            else if(i != 0 && j == 0)
                p[i][j] = t[i][j] + p[i - 1][j];
            else if(i == 0 && j != 0)
                p[i][j] = t[i][j] + p[i][j - 1];
            else
                p[i][j] = t[i][j];
        }
    }

    cin>>q;
    while(q--)
    {
        r = INT_MAX;
        scanf("%d %d",&a,&b);

        memset(dp,0,sizeof(dp));

                for(int d = 0; a * d < n; d++)
                    for(int d1 = 0; b * d1 < m; d1++)
                        for(int u = a * d; u < min(n,a * (d + 1)); u++)
                            for(int v = b * d1; v < min(m,b * (d1 + 1)); v++)
                                if(u != a * d && v != b * d1)
                                    dp[u][v][0][0] = mmax(dp[u][v][0][0], dp[u - 1][v - 1][0][0], dp[u - 1][v][0][0], dp[u][v - 1][0][0], t[u][v]);
                                else if(u != a * d && v == b * d1)
                                    dp[u][v][0][0] = max(dp[u][v][0][0], max(dp[u - 1][v][0][0], t[u][v]));
                                else if(u == a * d && v != b * d1)
                                    dp[u][v][0][0] = max(dp[u][v][0][0], max(dp[u][v - 1][0][0], t[u][v]));
                                else
                                    dp[u][v][0][0] = max(dp[u][v][0][0], t[u][v]);

                for(int d = 0; a * d < n; d++)
                    for(int d1 = 0; b * d1 < m; d1++)
                        for(int u = min(n - 1,a * (d + 1) - 1); u >= a * d; u--)
                            for(int v = min(m - 1,b * (d1 + 1) - 1); v >= b * d1; v--)
                                if(u != min(n - 1,a * (d + 1) - 1) && v != min(m - 1,b * (d1 + 1) - 1))
                                    dp[u][v][1][1] = mmax(dp[u][v][1][1], dp[u + 1][v + 1][1][1], dp[u + 1][v][1][1], dp[u][v + 1][1][1], t[u][v]);
                                else if(u != min(n - 1,a * (d + 1) - 1) && v == min(m - 1,b * (d1 + 1) - 1))
                                    dp[u][v][1][1] = max(dp[u][v][1][1], max(dp[u + 1][v][1][1], t[u][v]));
                                else if(u == min(n - 1,a * (d + 1) - 1) && v != min(m - 1,b * (d1 + 1) - 1))
                                    dp[u][v][1][1] = max(dp[u][v][1][1], max(dp[u][v + 1][1][1], t[u][v]));
                                else
                                    dp[u][v][1][1] = max(dp[u][v][1][1], t[u][v]);

                for(int d = 0; a * d < n; d++)
                    for(int d1 = 0; b * d1 < m; d1++)
                        for(int u = a * d; u < min(n,a * (d + 1)); u++)
                            for(int v = min(m - 1,b * (d1 + 1) - 1); v >= b * d1; v--)
                                if(u != a * d && v != min(m - 1,b * (d1 + 1) - 1))
                                    dp[u][v][0][1] = mmax(dp[u][v][0][1], dp[u - 1][v + 1][0][1], dp[u - 1][v][0][1], dp[u][v + 1][0][1], t[u][v]);
                                else if(u != a * d && v == min(m - 1,b * (d1 + 1) - 1))
                                    dp[u][v][0][1] = max(dp[u][v][0][1], max(dp[u - 1][v][0][1], t[u][v]));
                                else if(u == a * d && v != min(m - 1,b * (d1 + 1) - 1))
                                    dp[u][v][0][1] = max(dp[u][v][0][1], max(dp[u][v + 1][0][1], t[u][v]));
                                else
                                    dp[u][v][0][1] = max(dp[u][v][0][1], t[u][v]);

                for(int d = 0; a * d < n; d++)
                    for(int d1 = 0; b * d1 < m; d1++)
                        for(int u = min(n - 1,a * (d + 1) - 1); u >= a * d; u--)
                            for(int v = b * d1; v < min(m,b * (d1 + 1)); v++)
                                if(u != min(n - 1,a * (d + 1) - 1) && v != b * d1)
                                    dp[u][v][1][0] = mmax(dp[u][v][1][0], dp[u + 1][v - 1][1][0], dp[u + 1][v][1][0], dp[u][v - 1][1][0], t[u][v]);
                                else if(u != min(n - 1,a * (d + 1) - 1) && v == b * d1)
                                    dp[u][v][1][0] = max(dp[u][v][1][0], max(dp[u + 1][v][1][0], t[u][v]));
                                else if(u == min(n - 1,a * (d + 1) - 1) && v != b * d1)
                                    dp[u][v][1][0] = max(dp[u][v][1][0], max(dp[u][v - 1][1][0], t[u][v]));
                                else
                                    dp[u][v][1][0] = max(dp[u][v][1][0], t[u][v]);

                int m1;
                for(int i = 0; i + a - 1 < n; i++)
                    for(int j = 0; j + b - 1 < m; j++)
                    {
                        m1 = mmax(0,dp[i][j][1][1], dp[i][j + b - 1][1][0], dp[i + a - 1][j][0][1], dp[i + a - 1][j + b - 1][0][0]);
                        if(i != 0 && j != 0)
                            r = min(r,(m1 * a * b) - (p[i + a - 1][j + b - 1] - p[i + a - 1][j - 1] - p[i - 1][j + b - 1] + p[i - 1][j - 1]));
                        else if(i != 0 && j == 0)
                            r = min(r,(m1 * a * b) - (p[i + a - 1][j + b - 1] - p[i - 1][j + b - 1]));
                        else if(i == 0 && j != 0)
                            r = min(r,(m1 * a * b) - (p[i + a - 1][j + b - 1] - p[i + a - 1][j - 1]));
                        else
                            r = min(r,(m1 * a * b) - (p[i + a - 1][j + b - 1]));
                    }
        printf("%d\n",r);
    }
    return 0;
}
