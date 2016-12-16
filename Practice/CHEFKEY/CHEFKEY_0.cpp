#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m, c, cnt;
    cin>>t;
    while(t--)
    {
        cnt = 0;
        scanf("%d %d %d", &n, &m, &c);
        for(int i = 1; i * i <= c; i++)
        {
            if(c % i == 0)
            {
                int x = i;
                int y = c / i;
                if(x == y)
                {
                    if(1 <= x && x <= n && x <= m)
                        cnt++;
                }
                else
                {
                    if(1 <= x && x <= n && 1 <= y && y <= m)
                        cnt++;
                    if(1 <= y && y <= n && 1 <= x && x <= m)
                        cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}