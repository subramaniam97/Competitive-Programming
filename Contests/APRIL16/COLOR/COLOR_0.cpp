#include<bits/stdc++.h>
using namespace std;

int f[3];

int main()
{
    int t,n;
    string s;
    cin>>t;
    while(t--)
    {
        f[0] = f[1] = f[2] = 0;
        cin>>n>>s;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'R') f[0]++;
            else if(s[i] == 'G')f[1]++;
            else f[2]++;
        }
        cout<<min(f[0]+f[1],min(f[0]+f[2],f[1]+f[2]))<<endl;
    }
    return 0;
}