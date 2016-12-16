#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,a[100001],i;
    
    vector<int>::iterator p,q;
    cin>>t;
    while(t--)
    {
        vector<int> s;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            q=s.end()++;
            p=upper_bound(s.begin(),s.end(),a[i]);
            if(p==q)s.push_back(a[i]);
            else
            {
                s.at(p-s.begin())=a[i];
            }
        }
        cout<<s.size()<<" ";
        for(i=0;i<s.size();i++)
        cout<<s.at(i)<<" ";
        cout<<endl;
    }
    return 0;
}