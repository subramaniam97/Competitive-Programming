#include<bits/stdc++.h>
using namespace std;

int a[100001];

int main()
{
    int n, t, sum = 0;
    bool flag = 1, flag1 = 0, flag2;
    cin>>t;
    while(t--)
    {
        flag = 1;
        sum = flag1 = 0;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            if(a[i] == 2)
                flag = 0;
            if(a[i] == 5)
                flag1 = 1;
            sum += a[i];
        }
        flag2 = (sum >= (long long)(n) * 4.0) ? 1 : 0;
        if(flag && flag1 && flag2)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
