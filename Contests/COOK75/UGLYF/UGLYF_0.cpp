#include<bits/stdc++.h>
using namespace std;

int pos[27];
int help[27];

int main()
{
    int t;
    cin>>t;
    string a, b;
    int ans;
    while(t--)
    {
        ans = INT_MAX;
        memset(pos, -1, sizeof(pos));
        cin>>a>>b;
        for(int i = 0; i < 27; i++)
            help[i] = INT_MAX;
        for(int i = 0; i < b.length(); i++)
        {
            int x = i;
            int y = b.length() - x - 1;
            if(abs(x - y) < help[b[i] - 'A'])
                help[b[i] - 'A'] = abs(x - y);
        }
        for(int i = 0; i < b.length(); i++)
        {
            int x = i;
            int y = b.length() - x - 1;
            if(abs(x - y) == help[b[i] - 'A'])
                pos[b[i] - 'A'] = i;
        }
        for(int i = 0; i < a.length(); i++)
        {
            if(pos[a[i] - 'A'] == -1)
                continue;
            int l1 = i;
            int l3 = a.length() - l1 - 1;
            int l2 = pos[a[i] - 'A'];
            int l4 = b.length() - l2 - 1;
            ans = min(ans, abs(l1 - l2) + abs(l2 - l3) + abs(l3 - l4) + abs(l1 - l4));
        }
        cout<<ans<<endl;
    }
    return 0;
}
