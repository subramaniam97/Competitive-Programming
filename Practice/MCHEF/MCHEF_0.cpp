#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define MAX 100001
using namespace std;
 
ll n,a[MAX],m,l,r,c[MAX],cm[MAX],k,x,cm1[MAX],b[MAX];
vector<ll> l1[MAX],r1[MAX];
set<pair<ll,ll> > s;
ll dp[MAX][502];
 
void cmc()
{
    
    ll i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<l1[i].size();j++)
        {
            s.insert(mp(c[l1[i][j]],l1[i][j]));
        }
        
        if(s.size()>0)
        cm[i]=(*s.begin()).first;
        
        else
        cm[i]=567;
        
        for(j=0;j<r1[i].size();j++)
        {
            s.erase(mp(c[r1[i][j]],r1[i][j]));
        }
    }
}
 
ll maxi(ll a, ll b)
{
    return (a>b)?a:b;
}
 
ll solve()
{
    ll i,j;
 
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(j>=cm1[i-1])
            dp[i][j]=maxi(dp[i-1][j],dp[i-1][j-cm1[i-1]]+b[i-1]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[x][k];
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    ll t,i,j,ans;
    for(i=0;i<MAX;i++)dp[i][0]=0;
    for(i=0;i<502;i++)dp[0][i]=0;
    cin>>t;
    while(t--)
    {
        ans=0;
        x=0;
        s.clear();
        cin>>n>>k>>m;
        for(i=0;i<n;i++)
            {
                cin>>a[i];
                ans+=a[i];
                if(a[i]<0)
                {
                    b[x++]=-a[i];
                }
                l1[i].clear();
                r1[i].clear();
            }
        for(i=0;i<m;i++)
        {
            cin>>l>>r>>c[i];
             l1[l-1].pb(i);
            r1[r-1].pb(i);
        }
        cmc();
        x=0;
        for(i=0;i<n;i++)
        {
            if(a[i]<0)
            cm1[x++]=cm[i];
        }
        cout<<ans+solve()<<endl;
    }
    return 0;
}
 
 
// ^_^ \\ 