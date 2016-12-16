#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

ll MOD = 1000000000;

int c[4001][2001];
int m,n;
int memo[2001][2001];

void preprocess()
{
    int i,j;
    for(i=0;i<4001;i++)c[i][0]=1;
    for(i=1;i<4001;i++)
    {
        for(j=min(i,2000);j>0;j--)
        {
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%MOD;
        }
    }
}

int dp(int i,int s)
{
    if(s>m)return 0;
    if(i==n+1)return 1;
    if(memo[i][s]!=-1)return memo[i][s];
    memo[i][s]=(((ll)(dp(i+1,s))*c[s+m-1][m-1])%MOD + (ll)dp(i,s+1))%MOD;
    return memo[i][s];
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    preprocess();
    cin>>t;
    while(t--)
    {
        memset(memo,-1,sizeof(memo));
        cin>>n>>m;
        cout<<dp(1,0)<<endl;
    }
    return 0;
}


// ^_^ \\
