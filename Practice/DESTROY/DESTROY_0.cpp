#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;


map<int,int> m;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,x,k=0;
    cin>>t;
    while(t--)
    {
        m.clear();
        k=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            m[x]++;
            k=max(k,m[x]);
        }
        if(k>(n/2))cout<<k<<endl;
        else cout<<(n+1)/2<<endl;
    }
    return 0;
}


// ^_^ \\
