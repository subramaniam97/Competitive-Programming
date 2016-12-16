#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,i,x;
    long long int n;
    cin>>t;
    while(t--)
    {
	cin>>n;
	for(i=0;i<n;i++)cin>>x;
	if(n==1)cout<<"0\n"; 
	else
	{
		cout<<(n*(n-1))/2<<endl;
	}

    }
    return 0;
}
