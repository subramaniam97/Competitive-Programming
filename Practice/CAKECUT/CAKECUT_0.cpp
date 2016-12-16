#include<bits/stdc++.h>
using namespace std;

char a[1501][1501];
int xa[1501][1501];
bitset<1501> b[1501];
long long int r;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            scanf(" %c",&a[i][j]);
            xa[i][j] = xa[i - 1][j - 1] ^ xa[i][j - 1] ^ xa[i - 1][j] ^ (a[i][j] - '0');
        }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            b[i][m - j] = xa[i][j];

    for(int i = 0; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
        {
            bitset<1501> temp(b[i] ^ b[j]);
            int p = temp.count();
            int q = m - p;
            r += (p*(p - 1)) >> 1;
            r += (q*(q - 1)) >> 1;
            r += q;
        }
    printf("%lld\n",r);
    return 0;
}
