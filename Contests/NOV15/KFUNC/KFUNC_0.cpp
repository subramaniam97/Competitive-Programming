#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int m[9];

int get_sd(ll n)
{
    ll r,s=0;
    if(n<10)return n;
    while(n)
    {
        r = n%10;
        s += r;
        n = n/10;
    }
    return get_sd(s);
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll t,a,d,l,r,i,k,p,s,v=0,j;
    cin>>t;
    while(t--)
    {
        v =s= 0;
            cin>>a>>d>>l>>r;
          k = a = get_sd(a);
          for(i=1;i<=8;i++)
          {
                m[i] = k;
                k = (k+d)%9;
                if(k==0)k=9;
                s += m[i];
          }
          m[0] = k;
            s+=m[0];
          p = (r-l+1)/9;
          v += (p*s);

          r = r - (l+(p*9))+1;
          l = (l+(p*9))%9;
          for(i=l,j=1;j<=r;i++,j++)
          {
              v += m[i%9];
          }

          cout<<v<<endl;
    }
    return 0;
}
