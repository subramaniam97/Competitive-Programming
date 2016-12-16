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

int n,a[10001];
vector<int> b[10001];
vector<int>::iterator p;
int spf[10001];
int cntprimes[10001];
bool primes[10001];
ll r,tri,m1,tri1;

void pre()
{
    ll i,j;
    spf[1]=1;
    for(i=2;i<10001;i=i+2)spf[i]=2;
    for(i=3;i<10001;i=i+2)
    {
        if(!primes[i])
        {
            spf[i]=i;
            for(j=i;(j*i)<10001;j=j+2)
            {
                if(!primes[i*j]) primes[i*j]=1, spf[j*i]=i;
            }
        }
    }
     for(i=1;i<10001;i++)
    {
        int j;
        j=i;
        while(j>1)
        {
            while(spf[j/spf[j]]==spf[j])j/=spf[j];
            b[i].pb(spf[j]);
            j/=spf[j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int i,t,m,j,oddcount,gcd,oddgcd;
    bool f;
    pre();
    cin>>t;
    while(t--)
    {
        r=0;
        f=0;
        memset(cntprimes,0,sizeof(cntprimes));
        oddcount=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(i==0)
            {
                if(a[i]&1){f=1;oddcount++; oddgcd=a[i];}
                for(p=b[a[i]].begin();p!=b[a[i]].end();p++)
                    cntprimes[*p]++;
                gcd=a[i];
            }
            if(i>=1)
            {
                if(a[i]<a[i-1])
                {
                    r+=a[i-1]-a[i];
                    a[i]=a[i-1];
                     for(p=b[a[i]].begin();p!=b[a[i]].end();p++)
                    cntprimes[*p]++;
                    if(a[i]&1)
                    {
                        oddcount++;
                        if(f)oddgcd=__gcd(oddgcd,a[i]);
                        else
                        {
                            f=1;
                            oddgcd=a[i];
                        }
                    }
                    gcd=__gcd(gcd,a[i]);
                }
                else
                {
                    if(a[i]&1)
                    {
                        for(p=b[a[i]].begin();p!=b[a[i]].end();p++)
                        cntprimes[*p]++;
                        oddcount++;
                        if(f)oddgcd=__gcd(oddgcd,a[i]);
                        else
                        {
                            f=1;
                            oddgcd=a[i];
                        }
                    }
                    gcd=__gcd(gcd,a[i]);
                }
            }
        }
        if(gcd==1)
        {
        if(oddgcd==1)
        {
            m1=INT_MAX;
            for(i=1;i<10001;i++)
            {
                if(cntprimes[i]>=1)
                    {
                        tri=0;
                        for(j=0;j<n;j++)
                        {
                            tri+=abs(a[j]-((ceil(double(a[j])/i)*i)));
                        }
                        m1=min(m1,tri);
                    }
            }
            r+=min((ll)oddcount,m1);
        }
        else
        {
            tri1=INT_MAX;
            while(spf[oddgcd]>1)
            {
                tri=0;
                for(j=0;j<n;j++)
                {
                    tri+=abs(a[j]-((ceil(double(a[j])/spf[oddgcd])*spf[oddgcd])));
                }
                oddgcd/=spf[oddgcd];
                tri1=min(tri1,tri);
            }
            r+=min(tri1,(ll)oddcount);
        }
        }
        cout<<r<<endl;
    }
    return 0;
}


// ^_^ \\
