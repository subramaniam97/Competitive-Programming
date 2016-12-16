#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,y,r;
    string s,x;
    cin>>t;
    while(t--)
    {
        r = 0;
        cin>>n>>s;
        while(n--)
        {
            cin>>x;
            if(x.compare("CONTEST_WON") == 0)
            {
                cin>>y;
                r += 300 + max(20 - y,0);
            }
            else if(x.compare("TOP_CONTRIBUTOR") == 0)
            {
                r += 300;
            }
            else if(x.compare("CONTEST_HOSTED") == 0)
            {
                r += 50;
            }
            else
            {
                cin>>y;
                r += y;
            }
        }
        if(s.compare("INDIAN") == 0)
        {
            cout<<r/200<<endl;
        }
        else
        {
            cout<<r/400<<endl;
        }
    }
    return 0;
}
