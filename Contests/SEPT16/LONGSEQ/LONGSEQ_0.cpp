#include<bits/stdc++.h>
using namespace std;

int oc, zc;

int main()
{
    int t;
    string d;
    cin>>t;
    while(t--)
    {
        oc = zc = 0;
        cin>>d;
        for(int i = 0; i < d.length(); i++)
            if(d[i] == '0')
                zc++;
            else
                oc++;
        if(oc == 1 || zc == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
