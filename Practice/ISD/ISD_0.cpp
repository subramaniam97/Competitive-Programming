#include<bits/stdc++.h>
using namespace std;

int a[100001];

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        bool inc = 0;
        int r = 0;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            if(i == 1)
            {
                if(a[0] < a[1])
                    inc = 1;
                else
                    inc = 0;
            }
            if(i >= 2)
            {
                if(a[i - 1] < a[i])
                    if(inc == 0)
                        inc = 1, r++;
                if(a[i - 1] > a[i])
                    if(inc == 1)
                        inc = 0, r++;
            }
        }
        printf("%d\n",r);
    }
    return 0;
}
