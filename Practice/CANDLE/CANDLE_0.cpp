#include<bits/stdc++.h>
using namespace std;

int a[10];

int main()
{
    int t,r,m=9;
    bool done=0,zeromin=1;
    cin>>t;
    while(t--)
    {
        m=9;
        done=0;
        zeromin=1;
        for(int i=0;i<10;i++)
        {
            cin>>a[i];
            if(!done&&a[i]==0&&i!=0)
            {
                cout<<i<<endl;
                done=1;
            }
            m=min(m,a[i]);
        }
        for(int i=1;i<10;i++)
        {
            if(a[0]>=a[i])zeromin=0;
        }
        if(done)continue;
        if(zeromin)
        {
            cout<<"1";
            m++;
            while(m--)cout<<"0";
            cout<<endl;
            continue;
        }
        for(int i=0;i<10;i++)
        {
            if(m==a[i]&&i!=0)
            {
                m++;
                while(m--)cout<<i;
                cout<<endl;
                break;
            }
        }
    }
    return 0;
}