#include<bits/stdc++.h>
#define ll long long
using namespace std;

int p[2000001];
int m[1000001];
vector<int> a;

const int MOD=1000000007;

int fast_exp(int base,int exp)
 {
    ll int res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}

void sq(int n,int d)
{
    int i,r,x,c;
    x=d*d;
    c=0;
    for(i=0;i<n;i++)
    {
        m[i]=(x+c)%10;
        c=(x+c)/10;
    }
    m[n]=c;

    c=0;
    x=m[0];

    for(i=0;i<n;i++)
    {
        a.push_back((x+c)%10);
        c=(x+c)/10;
        x=(x+m[i+1]);

    }
    x=0;


    for(i=n;i>=1;i--)
    {
        x+=m[i];
    }


    for(i=1;i<=n;i++)
    {
        a.push_back((x+c)%10);
        c=(x+c)/10;
        x=x-m[i];
    }
    
    if(a[a.size()-1]==0)a.erase(a.end()-1);
}

ll int hash()
{
   ll int r,p;
   int i;
   r=0;
   p=1;
   for(i=a.size()-1;i>=0;i--)
   {
       r=(r+(a[i]*p)%MOD)%MOD;
       p=(p*23)%MOD;
   }
   return r;
}

int main()
{
    int t,n,d;
    scanf("%d",&t);
    while(t--)
    {
        a.clear();
        scanf("%d%d",&n,&d);
        sq(n,d);
        printf("%lld\n",hash());
    }
    return 0;
}
