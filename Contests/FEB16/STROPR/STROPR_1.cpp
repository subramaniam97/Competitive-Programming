#include<bits/stdc++.h>
#define getx getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
using namespace std;

ll MOD = 1000000007;

int a[100001];
int inv[100001];

ll raise(ll b, ll exp)
{
    ll r=1;
    while(exp)
    {
        if(exp&1)r=(r*b)%MOD;
        b=(b*b)%MOD;
        exp>>=1;
    }
    return r;
}

void preprocess()
{
    for(int i=1;i<=100000;i++)
    inv[i] = raise(i,MOD-2);
}

int main()
{
    //freopen("input.txt","r",stdin);
    int t,n,x;
    ll m,r=0,y,temp=1;
    scanf("%d",&t);
    while(t--)
    {
        r=0;
        temp = 1;
        scanf("%d %d %lld",&n,&x,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&y);
            a[i]=y%MOD;
        }
        m %= MOD;
        for(int i=0;i<=(x-1);i++)
        {
            r = (r + ((1LL)*a[x-i-1]*temp)%MOD)%MOD;
            temp = (temp*(m+i))%MOD;
            temp = (temp*raise(i+1,MOD-2))%MOD;
        }
        printf("%lld\n",r);
    }
    return 0;
}
