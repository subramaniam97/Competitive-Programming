#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll MOD = 1000000007;

ll raise(ll b,ll e)
{
    ll r=1;
    while(e)
    {
        if(e&1)r=(r*b)%MOD;
        b=(b*b)%MOD;
        e>>=1;
    }
    return r;
}

ll inv(ll n)
{
    return raise(n,MOD-2);
}

ll cmb(ll n,ll k)
{
    if(k<0||k>n)return 0;
    ll i=0,r=1;
    for(i=0;i<k;i++)
    {
        r=(r*(n-i))%MOD;
        r=(r*inv(i+1))%MOD;
    }
    return r;
}

int cnt[10];
int used[10];

int main()
{
    ios_base::sync_with_stdio(0);
    int i,j,k,l,t;
    ll ans=0;
    string s;
    cin>>t;
    while(t--)
    {
        ans=0;
        memset(cnt,0,sizeof(cnt));
        cin>>s;
        for(i=0;i<s.length();i++)
        {
            cnt[s[i]-'0']++;
        }
        for(i=0;i<11;i++)
        for(j=i;j<11;j++)
        for(k=j;k<11;k++)
        for(l=k;l<11;l++)
        {
            int sum=0;
            memset(used,0,sizeof(used));
            if(i<10) sum+=i, used[i]++;
            if(j<10) sum+=j, used[j]++;
            if(k<10) sum+=k, used[k]++;
            if(l<10) sum+=l, used[l]++;
            if(sum==0||sum%9)continue;
            ll r=1;
            for(int m=0;m<10;m++)
            r=(r*cmb(cnt[m],used[m]))%MOD;
            ans=(ans+r)%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}