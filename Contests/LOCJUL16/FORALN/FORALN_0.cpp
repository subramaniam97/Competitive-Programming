#include<bits/stdc++.h>
using namespace std;

map<string, pair<int, int> > m;

int main()
{
    int n;
    string s;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>s;
        string t;
        t = s[s.length() - 2];
        t += s[s.length() - 1];
        if(t != "ki" && t != "ka")
            continue;
        string u(s.begin(), s.begin() + s.length() - 2);
        if(t == "ki")
            m[u].first++;
        else
            m[u].second++;
    }
    int r = 0;
    for(map<string, pair<int, int> >::iterator it = m.begin(); it != m.end(); it++)
    {
        r += min((*it).second.first, (*it).second.second);
    }
    printf("%d\n", r);
    return 0;
}
