#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n;
int r[10004];

bool q1(int i, int j, int d)
{
    string x;
    printf("1 %d %d %d\n", i, j, d);
    fflush(stdout);
    cin>>x;
    if(x == "Yes")
        return 1;
    else
        return 0;
}

bool q2(int i, int j)
{
    string x;
    printf("2 %d %d\n", i, j);
    fflush(stdout);
    cin>>x;
    if(x == "Yes")
        return 1;
    else
        return 0;
}

void solve(vector<int> &v, int d)
{
    if(v.size() == 1)
        return;
    vector<int> v1, v2;
    v1.push_back(v[0]);
    for(int i = 1; i < v.size(); i++)
    {
        if(d <= n && q1(v[0], v[i], d))
            v1.push_back(v[i]);
        else
            v2.push_back(v[i]);
    }
    solve(v1, d * 2);
    solve(v2, d * 2);
    if(!q2(v1[0], v2[0]))
       swap(v1, v2);
    int p = 0, q = 0, i = 0;
    bool turn = 1;
    for(; p < v1.size() && q < v2.size(); i++)
    {
        if(turn)
        {
            v[i] = v1[p];
            p++;
        }
        else
        {
            v[i] = v2[q];
            q++;
        }
        turn = !turn;
    }
    if(turn)
    {
        while(p < v1.size())
        {
            v[i] = v1[p];
            p++;
            i++;
        }
    }
    else
    {
        while(q < v2.size())
        {
            v[i] = v2[q];
            q++;
            i++;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        v.clear();
        for(int i = 1; i <= n; i++)
            v.push_back(i);
        solve(v, 2);
        for(int i = 1; i <= n; i++)
            r[v[i - 1]] = i;
        printf("3 ");
        for(int i = 1; i <= n; i++)
            printf("%d ", r[i]);
        printf("\n");
        fflush(stdout);
    }
    return 0;
}
