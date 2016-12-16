#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,p,s;
    float r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&p,&s);
        r=p-sqrt(pow(p,2)-24*s);
        r/=12;
        r=r*r*((p/4)-(2*r));
        printf("%.2f\n",r);
    }
    return 0;
}