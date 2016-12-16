#include<bits/stdc++.h>
using namespace std;

long long a[505];

int main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        long long ans = 1e18;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                ans = min(ans, (a[i] * a[j]) / __gcd(a[i], a[j]));
        printf("%lld\n", ans);
    }
    return 0;
}
