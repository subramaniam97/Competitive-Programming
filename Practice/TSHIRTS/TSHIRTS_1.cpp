#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007
LL mpow(LL a, LL n)
{LL ret=1;LL b=a;while(n) {if(n&1)
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}
int toint(string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
LL dp[1025][109]={};
vector < int > arr[109];
int p;
LL rec(int mask, int shirt)
{
    LL r;
	if(mask==p) return dp[mask][shirt] = 1;
	if(shirt==101)return dp[mask][shirt] = 0;
	if(dp[mask][shirt]!=-1)return dp[mask][shirt];
	r = 0;
	r += rec(mask,shirt+1);
	r %= MOD;
	for(int i=0;i<arr[shirt].size();i++)
	{
		if(mask&(1<<(arr[shirt][i])))continue;
		r += rec((mask|(1<<(arr[shirt][i]))),shirt+1);
		r %= MOD;
	}
	return dp[mask][shirt] = r;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        int n,i,j;
        string ss,temp;
        cin >> n;
        getchar();
        for(i=0; i<=100; i++)
            arr[i].clear();
        for(i=0; i<n; i++)
        {
            getline(cin,ss);
            stringstream s (ss);
            while(s>>temp)
                arr[(toint(temp))].push_back(i);
        }
        p=(1<<n)-1;
        cout << rec(0,1) << endl;
    }
    return 0;
}
