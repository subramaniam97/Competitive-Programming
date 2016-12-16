#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long raise(long long b, long long exp)
{
    long long r = 1;
    while(exp)
    {
        if(exp & 1)
            r = (r * b) % MOD;
        b = (b * b) % MOD;
        exp >>= 1;
    }
    return r % MOD;
}

int main()
{
    int t;
    long long n;
    cin>>t;
    while(t--)
    {
        scanf("%lld", &n);
        if(n == 1)
            printf("0\n");
        else
            printf("%lld\n", (raise(2, n - 1) - 2 + MOD) % MOD);
    }
    return 0;
}
