#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int t;
    int n, r, r1;
    cin>>t;
    while(t--)
    {
        long long x = 0, y = 0;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            x += a[i];
        }
        y = x;
        r = r1 = n;
        while(x & 1)
        {
            r--;
            x -= a[r];
        }
        while(y & 1)
        {
            r1--;
            y -= a[n - r1 - 1];
        }
        printf("%d\n", max(r, r1));
    }
    return 0;
}
