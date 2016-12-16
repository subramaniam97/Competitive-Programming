#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int h,m;

bool check(int a,int b)
{
    int d;
    d = a%10;
    if(b==0&&a!=0)return 0;
    if(a==0&&b!=0)return 0;
    while(a)
    {
        if(d!=a%10)return 0;
        a /= 10;
    }
    while(b)
    {
        if(d!=b%10)return 0;
        b /= 10;
    }
    return 1;
}

int main()
{
    int t,n,r;
    scanf("%d",&t);
    while(t--)
    {
       r = 0;
       scanf("%d %d",&h,&m);
       for(int i = 0; i < h; i++)
       {
           for(int j = 0; j < m; j++)
           {
               r += check(i,j);
           }
       }
       printf("%d\n",r);
    }
    return 0;
}