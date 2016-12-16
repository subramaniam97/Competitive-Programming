#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}

int main()
{
	int t,n,a[1000],r,i;
	cin>>t;
	while(t--)
	{
		r=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			r=gcd(r,a[i]);
		}
		cout<<r<<endl;
	}
	return 0;
}
		