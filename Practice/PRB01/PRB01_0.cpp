#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
		j=1;
		cin>>n;
		for(i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				j=0;
				break;
			}	
		}
		if(j==1)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
	return 0;
}