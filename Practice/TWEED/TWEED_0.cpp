#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x;
    bool ev = 0;
    string s;
    cin>>t;
    while(t--)
    {
        ev = 0;
        cin>>n>>s;
        for(int i = 0; i < n; i++)
        {
            cin>>x;
            if(!(x & 1))
                ev = 1;
        }
        if(n == 1 && ev == 1 && s == "Dee")
            cout<<"Dee\n";
        else
            cout<<"Dum\n";
    }
    return 0;
}
