#include<bits/stdc++.h>
using namespace std;

int a[100005];

bool check(vector<int> x)
{
    int d = x[1] - x[0];
    for(int i = 1; i < x.size(); i++)
        if(x[i] - x[i - 1] != d)
            return 0;
    return 1;
}

int main()
{
    int t;
    long long n, b, m;
    cin>>t;
    while(t--)
    {
        set<int> s;
        cin>>n;
        for(int i = 0; i < n; i++)
            scanf(" %d", a + i);

        vector<int> x;

        for(int i = 1; i < n; i++)
            x.push_back(a[i]);
        if(check(x))
            s.insert(a[0]);

        x.clear();
        for(int i = 0; i < n - 1; i++)
            x.push_back(a[i]);
        if(check(x))
            s.insert(a[n - 1]);

        x.clear();
        for(int i = 0; i < n; i++)
            if(i != 1)
                x.push_back(a[i]);
        if(check(x))
            s.insert(a[1]);

        x.clear();
        for(int i = 0; i < n; i++)
            if(i != n - 2)
                x.push_back(a[i]);
        if(check(x))
            s.insert(a[n - 2]);

        int d1 = a[1] - a[0];
        int d2 = a[n - 1] - a[n - 2];

        if(d1 != d2 && s.empty())
        {
            printf("-1\n");
            continue;
        }

        x.clear();
        int d = d1, temp = -1;
        x.push_back(a[0]);
        for(int i = 1; i < n; i++)
        {
            if(a[i] - a[i - 1] == d)
                x.push_back(a[i]);
            else
            {
                temp = a[i];
                i++;
                for(; i < n; i++)
                    x.push_back(a[i]);
            }
        }
        if(temp != -1 && check(x))
            s.insert(temp);

        x.clear();
        d = d2;
        temp = -1;
        x.push_back(a[n - 1]);
        for(int i = n - 1; i >= 1; i--)
        {
            if(a[i] - a[i - 1] == d)
                x.push_back(a[i - 1]);
            else
            {
                temp = a[i];
                i--;
                for(; i >= 0; i--)
                    x.push_back(a[i]);
            }
        }
        reverse(x.begin(), x.end());
        if(temp != -1 && check(x))
            s.insert(temp);

        if(!s.empty())
            printf("%d\n", *(s.begin()));
        else
            printf("-1\n");
    }
    return 0;
}
