#include<iostream>
#include<cstdlib>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}

int main()
{
	int t,n,*a,i,m;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)cin>>a[i];
		m=a[0];
		for(i=1;i<n;i++)
		{
			m=gcd(a[i],m);
		}
		for(i=0;i<n;i++)
		{
			a[i]/=m;
			cout<<a[i]<<" ";
		}
		cout<<endl;
		free(a);
	}
	return 0;
}
			