#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;

ll MOD = 1000000007;
int done;

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

vector<int> a[110];
ll dp[1050][110];

ll solve(int mask, int cur)
{
    ll r;
	if(mask==done) return dp[mask][cur] = 1;
	if(cur==101)return dp[mask][cur] = 0;
	if(dp[mask][cur]!=-1)return dp[mask][cur];
	r = 0;
	r += solve(mask,cur+1);
	r %= MOD;
	for(int i=0;i<a[cur].size();i++)
	{
		if(mask&(1<<(a[cur][i]-1)))continue;
		r += solve((mask|(1<<(a[cur][i]-1))),cur+1);
		r %= MOD;
	}
	return dp[mask][cur] = r;
}

int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
int main()
{
	int t,n;
	string x,temp;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<101;i++)
		a[i].clear();
		x.clear();
		temp.clear();
		cin>>n;
		getchar();
		done = (1<<n)-1;
		for(int i=1;i<=n;i++)
		{
		    getline(cin,x);
            stringstream s (x);
            while(s>>temp)
            {
                a[(toint(temp))].pb(i);
            }
        }
        cout<<solve(0,1)<<endl;
    }
        return 0;
}
