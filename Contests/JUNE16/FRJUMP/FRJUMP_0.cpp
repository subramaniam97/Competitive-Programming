#include<bits/stdc++.h>
#define MOD 1000000007
#define epsilon 1e-9
using namespace std;

long long int a[100002];
long double b[100002];
long double ans1[321];
long long int ans2[321];
long long int f,r,n;

long long int raise(long long int b,long long int exp)
{
    long long int r = 1;
    while(exp)
    {
        if(exp & 1)
            r = (r * b) % MOD;
        b = (b * b) % MOD;
        exp >>= 1;
    }
    return r % MOD;
}


void pre()
{
    for(int i = 1; i * i <= n; i++)
    {
        long long int temp = 1;
        long double temp1 = 0;
        for(int j = 1; j <= n; j += i)
        {
            temp = (temp * a[j]) % MOD;
            temp1 = temp1 + b[j];
        }
        ans2[i] = temp;
        ans1[i] = temp1;
    }
}

int main()
{
    int t,q,c;
    scanf(" %lld",&n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %lld", a + i + 1);
        b[i + 1] = (long double)log10(a[i + 1]);
    }
    pre();
    scanf(" %d",&q);
    while(q--)
    {
        scanf(" %d",&t);
        if(t == 1)
        {
            scanf(" %d %lld",&c,&f);
            long double v = log10(f);
            long long int v1 = raise(a[c],MOD - 2);
            for(int i = 1; i * i <= n; i++)
            {
                if((c - 1) % i == 0)
                {
                    ans2[i] = (ans2[i] * v1) % MOD;
                    ans2[i] = (ans2[i] * f) % MOD;
                    ans1[i] = ans1[i] -  b[c] + v;
                }
            }
            a[c] = f;
            b[c] = v;
        }
        else
        {
            scanf(" %lld",&r);
            if(r * r <= n)
            {
                if(ceil(pow((long double)10,(long double)(ans1[r] - floor(ans1[r])))) - (pow((long double)10,(long double)(ans1[r] - floor(ans1[r])))) <= epsilon)
                    printf("%d %lld\n",(int)ceil(pow((long double)10,(long double)(ans1[r] - floor(ans1[r])))),ans2[r]);
                else
                    printf("%d %lld\n",(int)floor(pow((long double)10,(long double)(ans1[r] - floor(ans1[r])))),ans2[r]);
            }
            else
            {
                long long int temp = 1;
                long double temp1 = 0;
                for(int i = 1; i <= n; i += r)
                {
                    temp = (temp * a[i]) % MOD;
                    temp1 = temp1 + b[i];
                }
                if(ceil(pow((long double)10,(long double)(temp1 - floor(temp1)))) - (pow((long double)10,(long double)(temp1 - floor(temp1)))) <= epsilon)
                    printf("%d %lld\n",(int)ceil(pow((long double)10,(long double)(temp1 - floor(temp1)))),temp);
                else
                    printf("%d %lld\n",(int)floor(pow((long double)10,(long double)(temp1 - floor(temp1)))),temp);
            }
        }
    }
    return 0;
}
