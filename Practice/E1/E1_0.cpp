#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

ll MOD = 1000000007;

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

char a[1002][1002];
int dp[1002][1002];
int n;

int solve(int x,int y)
{
    if(x<0||x>n-1||y<0||y>n-1)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    int r=0;
    if(a[x][y]=='P')r++;
    r+=max(solve(x+2,y+1),max(solve(x+1,y+2),max(solve(x-1,y+2),solve(x-2,y+1))));
    return dp[x][y]=r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int i,t,j,x,y;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                {
                    cin>>a[i][j];
                    if(a[i][j]=='K')
                    {
                        x=i;
                        y=j;
                    }
                }
        cout<<solve(x,y)<<endl;
    }
    return 0;
}


// ^_^ \\
