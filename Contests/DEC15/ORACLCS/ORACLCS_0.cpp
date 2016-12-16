#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,m,i,j,ca,cb;
    string s;
    cin>>t;
    while(t--)
    {
        m=INT_MAX;
        cin>>n;
        for(i=0;i<n;i++)
        {
            ca=cb=0;
            cin>>s;
            for(j=0;j<s.length();j++)
            {
                if(s[j]=='a')ca++;
                else cb++;
            }
            m=min(m,min(ca,cb));
        }
        cout<<m<<endl;
    }
    return 0;
}


// ^_^ \\
