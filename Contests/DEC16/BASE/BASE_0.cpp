#include<bits/stdc++.h>
using namespace std;

long long n, k, r;

long long raise(long long b, long long e)
{
    long long r = 1;
    while(e)
    {
        if(e & 1)
            r = (r * b);
        b = (b * b);
        e >>= 1;
    }
    return r;
}

long long helper(long long n, long long k)
{
    long long l = 1;
    long long r;
    if(k == 40)
        r = 2;
    else if(k >= 30)
        r = 3;
    else if(k >= 20)
        r = 4;
    else if(k == 19)
        r = 8;
    else if(k == 18)
        r = 9;
    else if(k >= 12)
        r = 10;
    else if(k == 11)
        r = 13;
    else if(k == 10)
        r = 16;
    else if(k == 9)
        r = 24;
    else if(k == 8)
        r = 32;
    else if(k == 7)
        r = 80;
    else if(k == 6)
        r = 100;
    else if(k >= 4)
        r = 1545;
    else if(k == 3)
        r = 10545;
    else
        r = 1000000;
    while(l < r)
    {
        long long m = ((r - l) / 2) + l;
        if(raise(m, k) <= n)
            l = m + 1;
        else
            r = m;
    }
    return l - 1;
}

long long helper1(long long n, long long k)
{
    long long l = 1;
    long long r;
    if(k == 40)
        r = 2;
    else if(k >= 30)
        r = 3;
    else if(k >= 20)
        r = 4;
    else if(k == 19)
        r = 8;
    else if(k == 18)
        r = 9;
    else if(k >= 12)
        r = 10;
    else if(k == 11)
        r = 13;
    else if(k == 10)
        r = 16;
    else if(k == 9)
        r = 24;
    else if(k == 8)
        r = 32;
    else if(k == 7)
        r = 80;
    else if(k == 6)
        r = 100;
    else if(k >= 4)
        r = 1545;
    else if(k == 3)
        r = 10545;
    else
        r = 1000000;
    while(l < r)
    {
        long long m = ((r - l) / 2) + l;
        if(raise(m, k) < n)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        r = 0;
        scanf("%lld", &n);
        if(n == 0)
            printf("0\n");
        else if(n == 1)
            printf("INFINITY\n");
        else
        {
            for(int i = 2; i <= 40; i++)
            {
                long long temp = helper(n, i);
                long long temp1 = helper1((n / 2) + 1, i);
                r += max(0LL, temp - temp1 + 1);
            }
            printf("%lld\n", r + n - (n / 2));
        }
    }
    return 0;
}
