#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll a[400001], r; 
int mylife[10000001][2], mylife1[10000001][2];
ll lefty[400001], righty[400001];
int mycount;

void add(ll n)
{
    bool b[32];
    int cur = 0;
    int k = 0;
    while(n)
    {
        b[k++] = n%2;
        n /= 2;
    }
    for(; k < 32; k++)
    {
        b[k] = 0;
    }
    for(int i = 1; i <= 32; i++)
    {
        if(mylife[cur][b[32-i]] == 0)
        {
            mycount++;
            mylife[cur][b[32-i]] = mycount;
            cur = mycount;
        }
        else
        {
            cur = mylife[cur][b[32-i]];
        }
    }
}

void add1(ll n)
{
    bool b[32];
    int cur = 0;
    int k = 0;
    while(n)
    {
        b[k++] = n%2;
        n /= 2;
    }
    for(; k < 32; k++)
    {
        b[k] = 0;
    }
    for(int i = 1; i <= 32; i++)
    {
        if(mylife1[cur][b[32-i]] == 0)
        {
            mycount++;
            mylife1[cur][b[32-i]] = mycount;
            cur = mycount;
        }
        else
        {
            cur = mylife1[cur][b[32-i]];
        }
    }
}


ll query(ll n)
{
    ll ans = 0,x;
    bool b[32];
    bool c[32];
    int cur = 0;
    int k = 0;
    while(n)
    {
        b[k++] = n%2;
        n /= 2;
    }
    for(; k < 32; k++)
    {
        b[k] = 0;
    }
    k = 0;
    for(int i = 1; i <= 32; i++)
    {
        if(mylife[cur][!b[32-i]] == 0)
        {
            c[k++] = 0;
            cur = mylife[cur][b[32-i]];
        }
        else
        {
            c[k++] = 1;
            cur = mylife[cur][!b[32-i]];
        }
    }
    x = 1;
    for(int i = 31; i >= 0; i--)
    {
        ans += c[i]*x;
        x *= 2;
    }
    return ans;
}

ll query1(ll n)
{
    ll ans = 0,x;
    bool b[32];
    bool c[32];
    int cur = 0;
    int k = 0;
    while(n)
    {
        b[k++] = n%2;
        n /= 2;
    }
    for(; k < 32; k++)
    {
        b[k] = 0;
    }
    k = 0;
    for(int i = 1; i <= 32; i++)
    {
        if(mylife1[cur][!b[32-i]] == 0)
        {
            c[k++] = 0;
            cur = mylife1[cur][b[32-i]];
        }
        else
        {
            c[k++] = 1;
            cur = mylife1[cur][!b[32-i]];
        }
    }
    x = 1;
    for(int i = 31; i >= 0; i--)
    {
        ans += c[i]*x;
        x *= 2;
    }
    return ans;
}


int main()
{
    ll x, y;
    int n;
    r = 0;
    scanf(" %d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %lld",&a[i]);
    }

    lefty[0] = a[0];
    add(a[0]);
    x = a[0];
    add(0);
    for(int i = 1; i < n; i++)
    {
        lefty[i] = max(lefty[i-1], query(x^a[i]));
        add(x^a[i]);
        x = x^a[i];
    }

    mycount = 0;

    righty[n-2] = a[n-1];
    add1(a[n-1]);
    x = a[n-1];
    add1(0);
    for(int i = n - 3; i >= 0; i--)
    {
        righty[i] = max(righty[i+1], query1(x^a[i+1]));
        add1(x^a[i+1]);
        x = x^a[i+1];
    }

    for(int i = 0; i < n - 1; i++)
    {
        r = max(r,lefty[i] + righty[i]);
    }
    printf("%lld\n",r);
    return 0;
}
