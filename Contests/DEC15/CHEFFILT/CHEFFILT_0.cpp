#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

ll MOD = 1000000007;

string s,c;
ll mem[1024][1024];
ll cnt[1024];
ll twopow[100001];

ll raise(ll b, ll exp)
{
    if(exp<=0)return 1;
    if(twopow[exp])return twopow[exp];
    ll r=1;
    while(exp)
    {
        if(exp&1)r=(r*b)%MOD;
        b=(b*b)%MOD;
        exp>>=1;
    }
    return (twopow[exp]=r);
}


ll solve(ll i, ll k)
{
    if(i==-1&&k==0)return 1;
    if(i<0)return 0;
    if(mem[i][k]!=-1)return mem[i][k];
    if(cnt[i]>0)
        mem[i][k] = ((raise(2,cnt[i]-1))*(solve(i-1,k^i)%MOD + solve(i-1,k)%MOD))%MOD;
    else
        mem[i][k] = (raise(2,cnt[i]-1)*solve(i-1,k))%MOD;
    return mem[i][k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll t,n,i,j,d,x;
    cin>>t;
    while(t--)
    {
        for(i=0;i<1024;i++)
        {
            cnt[i]=0;
            for(j=0;j<1024;j++)
            mem[i][j]=-1;
        }
        d=0;
        cin>>s>>n;
        for(i=1;i<=n;i++)
        {
            cin>>c;
            x=0;
            for(j=0;j<10;j++)
            if(c[j]=='+')x+=raise(2,9-j);
            cnt[x]++;
        }
        for(i=0;i<10;i++)
        {
            if(s[i]=='w')d+=raise(2,9-i);
        }
        cout<<solve(1023,d)<<endl;
    }
    return 0;
}


// ^_^ \\
