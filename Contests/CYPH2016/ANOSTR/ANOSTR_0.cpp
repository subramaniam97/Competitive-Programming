#include<bits/stdc++.h>
using namespace std;

class cmp
{
    public:
    bool operator()(pair<int, pair<int, pair<int, string> > > a, pair<int, pair<int, pair<int, string> > > b)
    {
        if(a.first < b.first)
            return 1;
        if(a.first == b.first)
        {
            if(a.second.first < b.second.first)
                return 1;
            if(a.second.first == b.second.first)
            {
                if(a.second.second.first < b.second.second.first)
                    return 1;
                if(a.second.second.first == b.second.second.first)
                {
                    if(a.second.second.second < b.second.second.second)
                        return 1;
                }
            }
        }
        return 0;
    }
};

vector<pair<int, pair<int, pair<int, string> > > > r;

int main()
{
    int t, a, b, c;
    string d;
    cin>>t;
    while(t--)
    {
        r.clear();
        int n;
        cin>>n;
        while(n--)
        {
            scanf("%d %d %d", &a, &b, &c);
            cin>>d;
            r.push_back({a, {b, {c, d} } });
        }
        sort(r.begin(), r.end(), cmp());
        for(vector<pair<int, pair<int, pair<int, string> > > >::iterator it = r.begin(); it != r.end(); it++)
        {
            printf("%d %d %d ", (*it).first, (*it).second.first, (*it).second.second.first);
            cout<<(*it).second.second.second<<endl;
        }
    }
    return 0;
}
