#include<bits/stdc++.h>
using namespace std;

string s;
int n;

string place(int i, int j)
{
    if(i <= j)
    {
        string r(s.begin(), s.begin() + i);
        string r3(s.begin() + i + 1, s.begin() + j + 1);
        string r1(s.begin() + j + 1, s.end());
        string r2 = r + r3 + s[i] + r1;
        return r2;
    }
    else
    {
        string r(s.begin(), s.begin() + j);
        string r1(s.begin() + j, s.begin() + i);
        string r2(s.begin() + i + 1, s.end());
        string r3 = r + s[i] + r1 + r2;
        return r3;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        string r = s;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                //cout<<i<<" "<<j<<" "<<place(i,j)<<endl;
                r = min(r, place(i,j));
            }
        }
        cout<<r<<endl;
    }
    return 0;
}
