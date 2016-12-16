#include<iostream>
using namespace std;

int main()
{
	long long int t,i,s,n,a[50000],x;
	cin>>t;
	while(t--)
	{
		s=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			s+=a[i];
			
		}
		s=s/(n-1);
		for(i=0;i<n;i++)
		{
			cout<<s-a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}