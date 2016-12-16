#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

map<char, int> m;
long long f[100005];

void pre()
{
    f[0] = f[1] = 1;
    for(int i = 2; i <= 100000; i++)
        f[i] = (f[i - 1] * i) % MOD;
}

int main()
{
    pre();
    int t, l;
    string s;
    cin>>t;
    while(t--)
    {
        long long r = 1;
        l = 0;
        m.clear();
        cin>>s;
        for(int i = 0; i < s.length(); i++)
        {
            if(m.find(s[i]) == m.end())
                l++;
            m[s[i]]++;
        }
        for(map<char, int>::iterator it = m.begin(); it != m.end(); it++)
            r = (r * f[(*it).second]) % MOD;
        r = (r * f[l]) % MOD;
        printf("%lld\n", r);
    }
    return 0;
}
