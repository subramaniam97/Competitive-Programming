#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

map< pair<ll,ll> , set<double> > m;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,i,r,x,y,z,g;
    cin>>t;
    while(t--)
    {
        r=INT_MIN;
        cin>>n;
        m.clear();
        for(i=0;i<n;i++)
        {
            cin>>x>>y>>z;
            g=__gcd(x,y);
             m[mp(x/g,y/g)].insert(double(z)/g);
             r=max(r,int(m[mp(x/g,y/g)].size()));
        }
        cout<<r<<endl;
    }
    return 0;
}


// ^_^ \\
