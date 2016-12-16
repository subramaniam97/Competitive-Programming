#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int a[200005];

int main()
{
    int t, n;
    scanf(" %d", &t);
    while(t--)
    {
        bool f = 0;
        scanf(" %d", &n);
        for(int i = 0; i < n; i++)
            scanf(" %d", a + i);
        sort(a, a + n);
        for(int i = 1; i < n; i++)
            if(abs(a[i] - a[i - 1]) > 1)
            {
                f = 1;
                break;
            }
        if(!f)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
