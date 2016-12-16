#include<bits/stdc++.h>
using namespace std;

long long a[100005];

int main()
{
    int t, n;
    long long p, q;
    cin>>t;
    while(t--)
    {
        long long cnt = 0;
        scanf("%d %lld %lld", &n, &p, &q);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++)
        {
            if(a[i] & 1)
            {
                q -= (a[i] >> 1);
                if(q >= 0)
                {
                    p -= 1;
                    if(p >= 0)
                        cnt++;
                    else
                        p += 1, q += (a[i] >> 1);
                }
                else
                {
                    q += (a[i] >> 1LL);
                    int temp = q;
                    int req = a[i] - 2LL * q;
                    q = 0;
                    p -= req;
                    if(p >= 0)
                        cnt++;
                    else
                        p += req, q = temp;
                }
            }
            else
            {
                q -= (a[i] >> 1);
                if(q >= 0)
                    cnt++;
                else
                {
                    q += (a[i] >> 1);
                    int temp = q;
                    int req = a[i] - 2LL * q;
                    q = 0;
                    p -= req;
                    if(p >= 0)
                        cnt++;
                    else
                        p += req, q = temp;
                }
            }
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
