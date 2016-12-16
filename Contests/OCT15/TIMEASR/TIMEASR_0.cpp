#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t,h1,m1;
    float d,m,h;
    cin>>t;
    while(t--)
    {
        h=m=0;
        cin>>d;
        while(h<360)
        {
            m=0;
            while(m<360)
            {
                if(fabs(fabs(h-m)-d)<=(float)1/120||fabsf(fabsf(360-fabs(h-m))-d)<=(float)1/120)
                {
                    h1=h/30;
                    m1=m/6;
                    if(h1<10&&m1<10)
                        printf("0%d:0%d\n",h1,m1);
                    else if(h1<10&&m1>=10)
                        printf("0%d:%d\n",h1,m1);
                    else if(h1>=10&&m1<10)
                        printf("%d:0%d\n",h1,m1);
                    else if(h1>=10&&m1>=10)
                        printf("%d:%d\n",h1,m1);
                }
                 m+=6;
                 h+=0.5;
            }
        }
    }

return 0;
}
