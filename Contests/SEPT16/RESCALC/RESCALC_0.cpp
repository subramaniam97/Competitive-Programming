#include<bits/stdc++.h>
using namespace std;

int score[102];
set<int> se;

int main()
{
    int t, s, n, x;
    cin>>t;
    while(t--)
    {
        se.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            int cnt[7] = {0};
            scanf("%d", &s);
            for(int j = 1; j <= s; j++)
            {
                scanf("%d", &x);
                cnt[x]++;
            }
            score[i] = s;
            sort(cnt + 1, cnt + 7);

            int six = cnt[1];
            score[i] += six * 4;
            for(int k = 1; k <= 6; k++)
                cnt[k] -= six;

            int five = cnt[2];
            score[i] += five * 2;
            for(int k = 1; k <= 6; k++)
                cnt[k] -= five;

            int four = cnt[3];
            score[i] += four;
            for(int k = 1; k <= 6; k++)
                cnt[k] -= four;
        }
        int maxi = 0;
        for(int i = 1; i <= n; i++)
        {
            maxi = max(maxi, score[i]);
        }
        bool fail = 0;
        for(int i = 1; i <= n; i++)
        {
            if(score[i] == maxi && (se.find(score[i]) == se.end()))
                se.insert(score[i]);
            else if(score[i] == maxi && (se.find(score[i]) != se.end()))
            {
                printf("tie\n");
                fail = 1;
                break;
            }
        }
        if(fail)
            continue;

        if(score[1] == maxi)
        {
            printf("chef\n");
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            if(score[i] == maxi)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
