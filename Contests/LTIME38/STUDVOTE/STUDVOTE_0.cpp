#include<bits/stdc++.h>
using namespace std;

int a[102];
bool v[102];

int main()
{
    int t, n, k, x;
    cin>>t;
    while(t--)
    {
        int cnt = 0;
        memset(v, 0, sizeof(v));
        memset(a, 0, sizeof(a));
        cin>>n>>k;
        for(int i = 1; i <= n; i++)
        {
            cin>>x;
            if(i == x)
                v[i] = 1;
            a[x]++;
        }
        for(int i = 1; i <= n; i++)
        {
            if(!v[i] && a[i] >= k)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
