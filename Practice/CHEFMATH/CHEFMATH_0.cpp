#include<bits/stdc++.h>
using namespace std;

int f[43];

void pre()
{
    f[0] = 1;
    f[1] = 2;
    for(int i = 2; i < 43; i++)
        f[i] = f[i-1] + f[i-2];
}

int solve(int n, int r, int l)
{
    if(1LL*n == 1LL*r*l) return 1;
    if(1LL*n > 1LL*r*l) return 0;
    int ans = 0;
    for(int i = 0; i < 43; i++)
    {
        if(n < f[i] || f[i] > l) break;
        ans += solve(n-f[i],r-1,f[i]);
    }
    return ans;
}

int main()
{
    pre();
    int t,x,k;
    cin>>t;
    while(t--)
    {
        cin>>x>>k;
        cout<<solve(x,k,x+1)<<endl;
    }
    return 0;
}
