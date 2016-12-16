#include<bits/stdc++.h>
using namespace std;

long long ans;

int main()
{
    string a, b, c;
    int t, n;
    cin>>t;
    while(t--)
    {
        int ind = -1;
        long long temp = 0;
        bool flag = 0;
        ans = 0;
        cin>>a>>b>>c>>n;
        for(int i = b.length() - 1; i >= 0; i--)
        {
            if(b[i] == '1')
                temp++;
            if(ind == -1 && b[i] == '0')
                ind = i;
        }
        if(ind != -1)
            ind = b.length() - ind - 1;
        for(int i = c.length() - 1; i >= 0; i--)
        {
            if(!flag && c[i] == '0')
            {
                ans++;
                flag = 1;
            }
            if(flag && c[i] == '1')
                ans++;
        }
        if(flag)
        {
            ans += (temp * n);
            for(int i = 0; i < a.length(); i++)
                if(a[i] == '1')
                    ans++;
        }
        else
        {
            if(ind != -1)
            {
                ans++;
                ans += (temp * n) - (ind);
                for(int i = 0; i < a.length(); i++)
                    if(a[i] == '1')
                        ans++;
            }
            else
            {
                bool flag1 = 0;
                 for(int i = a.length() - 1; i >= 0; i--)
                 {
                    if(!flag1 && a[i] == '0')
                    {
                        ans++;
                        flag1 = 1;
                    }
                    if(flag1 && a[i] == '1')
                        ans++;
                }
            }
        }
        printf("%lld\n", max(1LL, ans));
    }
    return 0;
}
