#include<bits/stdc++.h>
using namespace std;

int a[100005], n;
set<int> s, s1, s2;

int next(int i)
{
    int r = ((long long)a[i] + i + 1) % n;
    if(r == 0)
        return n;
    return r;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        s.clear();
        s1.clear();
        s2.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", a + i);
        for(int i = 1; i <= n; i++)
        {
            if(s.find(i) == s.end())
            {
                s.insert(i);
                int j = next(i);
                while(s.find(j) == s.end())
                {
                    s.insert(j);
                    j = next(j);
                }
                if(s2.find(j) != s2.end())
                {
                    int k = i;
                    while(k != j)
                    {
                        s2.insert(k);
                        k = next(k);
                    }
                    continue;
                }
                if(i != j)
                {
                    int k = i;
                    while(k != j)
                    {
                        s2.insert(k);
                        k = next(k);
                    }
                }
                int k = next(j);
                if(s1.find(j) == s1.end())
                {
                    s1.insert(j);
                    while(k != j)
                    {
                        if(s1.find(k) == s1.end())
                            s1.insert(k);
                        k = next(k);
                    }
                }
            }
        }
        printf("%d\n", s1.size());
    }
    return 0;
}
