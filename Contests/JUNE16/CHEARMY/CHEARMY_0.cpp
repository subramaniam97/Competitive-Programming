#include<bits/stdc++.h>
using namespace std;

int a[] = {0, 2, 4, 6, 8};

int main()
{
    int t,x;
    long long int k,n,y,r;
    cin>>t;
    while(t--)
    {
        scanf(" %lld", &k);
        y = 1;
        r = 0;
        k--;
        while(k)
        {
            x = k % 5;
            r += 1LL * a[x] * y;
            y *= 10LL;
            k /= 5;
        }
        printf("%lld\n",r);
    }
    return 0;
}
