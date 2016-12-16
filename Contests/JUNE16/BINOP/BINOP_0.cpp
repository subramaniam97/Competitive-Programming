#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,x,y;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        x = y = 0;
        bool zeroAvailable = 0, oneAvailable = 0;
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] == '0') zeroAvailable = 1;
            if(a[i] == '1') oneAvailable = 1;
            if(a[i] != b[i] && a[i] == '0') x++;
            if(a[i] != b[i] && a[i] == '1') y++;
        }
        if((zeroAvailable == 0 && y > 0) || (oneAvailable == 0 && x > 0))
            cout<<"Unlucky Chef\n";
        else
        {
            cout<<"Lucky Chef\n";
            cout<<max(x,y)<<endl;
        }
    }
    return 0;
}
