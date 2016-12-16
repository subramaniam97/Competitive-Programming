#include<bits/stdc++.h>
using namespace std;

int a[500][500];

int main()
{
    int t, k;
    cin>>t;
    while(t--)
    {
        scanf("%d", &k);

        for(int i = 1; i <= k; i++)
            a[(k + 1) / 2][i] = i;

        int x = 1;
        for(int i = ((k + 1) / 2) + 1; i <= k; i++)
        {
            for(int j = 1; j <= k; j++)
                a[i][j] = ((j + k - x) % k == 0) ? k : ((j + k - x) % k);
            x++;
        }

        for(int i = 1; i < (k + 1) / 2; i++)
        {
            for(int j = 1; j <= k; j++)
                a[i][j] = ((j + k - x) % k == 0) ? k : ((j + k - x) % k);
            x++;
        }


        for(int i = 1; i <= k; i++)
        {
            for(int j = 1; j <= k; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
