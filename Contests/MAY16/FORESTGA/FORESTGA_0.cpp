#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll h[100001],r[100001],m[100001];
vector<pair<ll,pair<ll,ll> > > v;

int main()
{
    int n;
    ll x,w,l,ans = 1000000000000000000LL,h1 = 0,r1 = 0,t;
    scanf(" %d %lld %lld",&n,&w,&l);
    for(int i = 0; i < n; i++)
    {
        scanf(" %lld %lld", &h[i],&r[i]);
        if(l <= h[i]) m[i] = 0;
        else m[i] = ceil((l - h[i])/((long double)r[i]));
        v.push_back(make_pair(m[i],make_pair(h[i],r[i])));
    }
    sort(v.begin(),v.end());
    t = (*(v.begin())).first;
    for(vector<pair<ll,pair<ll,ll> > >::iterator it = v.begin(); it != v.end(); it++)
    {
        if((*it).first > t)
        {
            x = ceil((w - h1)/((long double)r1));
            ans = min(ans,max(x,t));
            t = (*it).first;
        }
        h1 += (*it).second.first;
        r1 += (*it).second.second;
    }
    x = ceil((w - h1)/((long double)r1));
    ans = min(ans,max(x,t));
    printf("%lld\n",ans);
    return 0;
}
