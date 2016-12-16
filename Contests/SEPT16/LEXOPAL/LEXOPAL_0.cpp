#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        bool flag = 1;
        for(int i = 0; i <= (s.length()) >> 1; i++)
        {
            if(s[i] == '.' && s[s.length() - i - 1] == '.')
                s[i] = s[s.length() - i - 1] = 'a';
            else if(s[i] == '.')
                s[i] = s[s.length() - i - 1];
            else if(s[s.length() - i - 1] == '.')
                s[s.length() - i - 1] = s[i];
            else
            {
                if(s[i] != s[s.length() - i - 1])
                {
                    flag = 0;
                    printf("-1\n");
                    break;
                }
            }
        }
        if(flag)
            cout<<s<<endl;
    }
    return 0;
}
