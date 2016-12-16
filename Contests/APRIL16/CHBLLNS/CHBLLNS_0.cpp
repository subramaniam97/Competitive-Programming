#include<bits/stdc++.h>
using namespace std;

long long int ans;

int main()
{
    int t,r,g,b,k;
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>r>>g>>b>>k;
        ans += min(r, k - 1);
        ans += min(g, k - 1);
        ans += min(b, k - 1);
        ans++;
        cout<<ans<<endl;
    }
    return 0;
}