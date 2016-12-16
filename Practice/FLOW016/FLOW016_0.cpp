#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	int a,b,t,g;
	long long int l;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		g=gcd(a,b);
		l=(a*b)/g;
		cout<<g<<" "<<l<<endl;
	}
	return 0;
}