#include<bits/stdc++.h>
using namespace std;

long long int a[1001];
vector<int> p[1001];
map<int, int> m;
bool done[1001];
long long int n, r;
int k;

void pre()
{
    k = 1;
    m.clear();
    for(int i = 0; i < 1001; i++)
        p[i].clear();
    memset(done, 0, sizeof(done));
    for(int i = 0; i < n; i++)
        if(m[a[i]] == 0)
            m[a[i]] = k++;

    for(int i = 0; i < n; i++)
    {
        if(done[m[a[i]]])
            continue;
        for(int j = 0; j < n; j++)
            if(a[i] == a[j])
                p[m[a[i]]].push_back(j);
        done[m[a[i]]] = 1;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        r = 0;
        cin>>n;
        for(int i = 0; i < n; i++)
            scanf("%lld", a + i);
        pre();
        for(int i = 0; i < n; i++)
        {
            set<int> es;
            set<int> ps;
            ps.insert(i);
            ps.insert(n);
            long long int temp = ((n - i - 1) * (n - i)) >> 1;
            for(int j = i; j < n; j++)
            {
                set<int>::iterator it2 = ps.lower_bound(j);
                temp -= ((*it2) - j);
                ps.insert(j);
                if(es.find(a[j]) != es.end())
                {
                    r += temp;
                    continue;
                }
                es.insert(a[j]);
                for(vector<int>::iterator it = p[m[a[j]]].begin(); it != p[m[a[j]]].end(); it++)
                {
                    int q = *it;
                    if(q > j)
                    {
                        set<int>::iterator it1 = ps.lower_bound(q);
                        int x = *it1;
                        if(it1 != ps.begin())
                            it1--;
                        int y = *it1;
                        temp -= ((q - y) * (x - q));
                        ps.insert(q);
                    }
                }
                r += temp;
            }
        }
        cout<<r<<endl;
    }
    return 0;
}
