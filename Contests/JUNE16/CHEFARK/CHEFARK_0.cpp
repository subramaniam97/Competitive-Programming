#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long int r;
long long int f[100001],invf[100001];

long long int raise(long long int b,long long int e)
{
    long long int r = 1;
    while(e)
    {
        if(e & 1) r = (r * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return r % MOD;
}

void pre()
{
    f[0] = f[1] = 1;
    invf[0] = invf[1] = 1;
    for(int i = 2; i <= 100000; i++)
    {
        f[i] = (f[i - 1] * i) % MOD;
        invf[i] = (invf[i  - 1] * raise(i,MOD - 2)) % MOD;
    }
}

int main()
{
    int t,x,n1,k,n;
    pre();
    scanf(" %d",&t);
    while(t--)
    {
        n = r = 0;
        scanf(" %d %d",&n1,&k);
        for(int i = 0; i < n1; i++)
        {
            scanf(" %d",&x);
            if(x != 0) n++;
        }
        if(n != n1)
        {
            for(int i = 0; i <= k; i ++)
            {
                if(i > n) break;
                r += (invf[i] * invf[n - i]) % MOD;
                r %= MOD;
            }
        }
        else
        {
            if(k & 1)
                for(int i = 1; i <= k; i += 2)
                {
                    if(i > n) break;
                    r += (invf[i] * invf[n - i]) % MOD;
                    r %= MOD;
                }
            else
                for(int i = 0; i <= k; i += 2)
                {
                    if(i > n) break;
                    r += (invf[i] * invf[n - i]) % MOD;
                    r %= MOD;
                }
        }
        r = (r * f[n]) % MOD;
        printf("%lld\n",r);
    }
    return 0;
}
