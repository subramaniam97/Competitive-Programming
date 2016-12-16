#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll bit2[1000010];
int n;

void update2(int i,int v)
{
    while(i<=n)
    {
        bit2[i]+=(ll)v;
        i=i+(i&(-i));
    }
}

ll q2(int i)
{
    ll s=0;
    while(i)
    {
        s+=bit2[i];
        i=i-(i&(-i));
    }
    return s;
}

int main()
{
   int m,c,x,y,v;
   scanf(" %d %d %d",&n,&m,&c);
   update2(1,c);
   char c1;
   while(m--)
   {
       scanf(" %c ",&c1);
       if(c1=='S')
       {
           scanf(" %d %d %d",&x,&y,&v);
           update2(x,v);
           update2(y+1,-v);
       }
       else
       {
           scanf(" %d ",&v);
           printf("%lld\n",q2(v));
       }
   }
   return 0;
}
