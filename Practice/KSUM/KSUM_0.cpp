#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
using namespace std;

set<pair<ll,pair<int,int> > > s;
int a[100001];

int main()
{
    int n,k,l,r;
    ll x;
    cin>>n>>k;
    x = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        x += a[i];
    }
    s.insert(mp(x,mp(0,n-1)));
    while(k--)
    {
        pair<ll,pair<int,int> > y = *(s.rbegin());
        cout<<y.first<<" ";
        x = y.first;
        l = y.second.first;
        r = y.second.second;
        s.erase(y);
        if(l < n)s.insert(mp(x-a[l],mp(l+1,r)));
        if(r >= 0)s.insert(mp(x-a[r],mp(l,r-1)));
    }
    return 0;
}