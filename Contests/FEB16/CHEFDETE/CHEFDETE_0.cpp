#include<bits/stdc++.h>
using namespace std;

bool report[100001];

int main()
{
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		report[x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!report[i])
		{
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}
