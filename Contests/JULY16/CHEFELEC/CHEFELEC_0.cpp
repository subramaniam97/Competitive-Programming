#include<bits/stdc++.h>
using namespace std;

string b;
int a[100001];

int main()
{
    int t, n, r, k, p1, q1, m;
    scanf("%d",&t);
    while(t--)
    {
        r = 0;
        scanf("%d",&n);
        cin>>b;
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        int p = 0;
        int q = n - 1;
        while(b[p] == '0')
            p++;
        while(b[q] == '0')
            q--;
        r += a[p] - a[0];
        r += a[n - 1] - a[q];
        k = p;
        for(int i = p + 1; i <= q; i++)
        {
            if(b[i] == '1')
            {
                p1 = k;
                q1 = i;
                int s = 0;
                int temp = 0;
                for(int j = k + 1; j <= i; j++)
                {
                    s += a[j] - a[j - 1];
                    temp = max(temp, a[j] - a[j - 1]);
                }
                r += s - temp;
                k = i;
            }
        }
        printf("%d\n",r);
    }
    return 0;
}
