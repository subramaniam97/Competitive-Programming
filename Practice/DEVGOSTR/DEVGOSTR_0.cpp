#include<bits/stdc++.h>
using namespace std;

vector<string> thegold[51][4];
char temp[51];

void solve(int len, int alpha)
{
    temp[len] = '\0';
    thegold[len][alpha].push_back(temp);
    for(char ch = 'a'; ch < 'a' + alpha; ch++)
    {
        bool good = 1;
        temp[len] = ch;
        for(int i = 0; i < len; i++)
        {
            if(!((i+len)&1))
            {
                if(temp[i] == temp[len] && temp[i] == temp[(i + len)/2])
                {
                    good = 0;
                }
            }
        }
        if(good)
        {
            solve(len + 1, alpha);
        }
    }
}

int main()
{
    solve(0,1);
    solve(0,2);
    solve(0,3);
    int t,n,a,k,x,r;
    string s;
    cin>>t;
    while(t--)
    {
        r = 0;
        cin>>a>>k>>s;
        for(vector<string>::iterator p = thegold[s.length()][a].begin(); p != thegold[s.length()][a].end(); p++)
        {
            x = 0;
            for(int i = 0; i < s.length(); i++)
            {
                if(s[i] != (*p)[i]) x++;
            }
            if(x <= k) r++;
        }
        cout<<r<<endl;
    }
    return 0;
}
