#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,i,a[101],k;
    cin>>t;
    while(t--)
    {
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	cin>>k;
	k=a[k];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		if(a[i]==k)break;
	}
	cout<<i<<endl;
    }
    return 0;
}
