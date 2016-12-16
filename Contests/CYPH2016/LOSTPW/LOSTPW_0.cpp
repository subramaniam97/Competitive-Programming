#include<bits/stdc++.h>
using namespace std;

set<char> se;

int main()
{
    while(1)
    {
        se.clear();
        string s;
        cin>>s;
        for(int i = 0; i < s.length(); i++)
            se.insert(s[i]);
        if(se.size() == s.length())
        {
            printf("Valid\n");
            return 0;
        }
        else
            printf("Invalid\n");
    }
    return 0;
}