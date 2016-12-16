#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    int c,t,n,i,m;
    cin>>t;
    while(t--)
    {
    	c=0;
    	cin>>n>>m;
    	i=__gcd(n,m);
        if(i==1)cout<<"Yes\n";
    	else
    	{
    		cout<<"No "<<n/i<<endl;
    	}

    }
    return 0;
}
