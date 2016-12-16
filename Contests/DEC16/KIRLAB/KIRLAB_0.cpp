#include<bits/stdc++.h>
using namespace std;

int a[100005];
bool primes[10000005];
int spf[10000005];
int dp[10000005];
int ans[100005];

void pre()
{
    spf[1] = 1;
    for(int i = 2; i < 10000001; i += 2)
        spf[i] = 2;
    for(int i = 3; i < 10000001; i += 2)
    {
        if(!primes[i])
        {
            spf[i] = i;
            for(long long j = i; j * i < 10000001; j += 2)
            {
                if(!primes[j * i])
                {
                    primes[j * i] = 1;
                    spf[j * i] = i;
                }
            }
        }
    }
}

int main()
{
    pre();
    int t, r, n;
    scanf("%d", &t);
    while(t--)
    {
        r = 0;
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; i++)
            scanf("%d", a + i);
        for(int i = 0; i < n; i++)
        {
            int j;
            j = a[i];
            while(j > 1)
            {
                while(spf[j / spf[j]] == spf[j])
                    j /= spf[j];

                if(dp[spf[j]] != -1)
                    ans[i] = max(ans[i], ans[dp[spf[j]]] + 1);
                else
                    ans[i] = max(ans[i], 1);
                dp[spf[j]] = i;

                j /= spf[j];
            }
        }
        for(int i = 0; i < n; i++)
            r = max(r, ans[i]);
        printf("%d\n", max(1, r));
    }
    return 0;
}
