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

char a[1010][1010];
int c;
vector<int> xx,yy;

ll solve(int x,int y)
{
    ll r=0;
    int i;
    for(i=0;i<c;i++)
    {
        r=max(r,(ll)max((ll)abs(xx[i]-x),(ll)abs(yy[i]-y)));
    }
    return r;
}



int main()
{
    ios_base::sync_with_stdio(0);
    ll i,j,t,n,m,x_min,x_max,y_min,y_max,x,y;
    ll r;
    cin>>t;
    while(t--)
    {
        x_min=y_min=INT_MAX;
        x_max=y_max=INT_MIN;
        xx.clear();
        yy.clear();
        r=INT_MAX;
        c=0;
        cin>>n>>m;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                {
                    cin>>a[i][j];
                    if(a[i][j]=='*')
                    {
                        xx.pb(i);
                        yy.pb(j);
                        x_min=min(x_min,i);
                        y_min=min(y_min,j);
                        x_max=max(x_max,i);
                        y_max=max(y_max,j);
                        c++;
                    }
                }
        if(c==0)cout<<"0\n";
        else
        {
             x=(x_min+x_max)/2;
             y=(y_min+y_max)/2;
             r=min(r,solve(x,y));
             cout<<r+1<<endl;
        }
    }
    return 0;
}
