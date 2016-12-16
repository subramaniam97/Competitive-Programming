#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t,l,n,k,i,j,p,c[101];
    string a[101],b[101][501];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0;i<n;i++)
        cin>>a[i];
        for(i=0;i<k;i++)
        {
            cin>>l;
            c[i]=l;
            for(j=0;j<l;j++)
            cin>>b[i][j];
        }
        for(p=0;p<n;p++)
        {
            for(i=0;i<k;i++)
            {
                   l=c[i];
                    for(j=0;j<l;j++)
                    {
                        if(a[p].compare(b[i][j])==0){cout<<"YES "; goto a;}
                    }
                
            }
            cout<<"NO ";
            a:
            cout<<"";
        }
        cout<<endl;
    }
	return 0;
}
