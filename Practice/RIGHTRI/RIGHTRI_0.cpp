#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> p;

int d(p a,p b)
{
   return pow((a.first-b.first),2)+pow((a.second-b.second),2);
}

int yay(p a,p b,p c)
{
   int x=d(a,b),y=d(b,c),z=d(c,a);
   if(x+y==z||y+z==x||x+z==y) return 1;
   return 0;
}


int main()
{
   int t,r=0;

   scanf("%d",&t);

   while(t--)
   {
      p a,b,c;
      scanf("%d%d",&a.first,&a.second);
      scanf("%d%d",&b.first,&b.second);
      scanf("%d%d",&c.first,&c.second);
      if(yay(a,b,c)) r++;
   }

   printf("%d\n",r);

	return 0;
}
 
