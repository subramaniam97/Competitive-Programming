#include<bits/stdc++.h>
using namespace std;

int x[300001],y[300001],a[300001],b[300001];

int main()
{
	long long n,m,c1,c2;
	string path;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	cin>>path;
	sort(x,x+n);
	sort(y,y+n);
	
	a[0]=x[0],b[0]=y[0];
	for(int i=1;i<n;i++)
	{
		a[i]=a[i-1]+x[i];
		b[i]=b[i-1]+y[i];
	}
	long long int cx=0,cy=0,r=0;
	for(int i=0;i<m;i++)
	{
		r=0;
		switch(path[i])
		{
			case 'U' : cy++; break;
			case 'L' : cx--; break;
			case 'D' : cy--; break;
			case 'R' : cx++; break;
		}
		c1=upper_bound(x,x+n,cx)-x;
		r+=(c1*cx)-a[c1-1]-(n-c1)*cx+(a[n-1]-a[c1-1]);
		c2=upper_bound(y,y+n,cy)-y;
		r+=(c2*cy)-b[c2-1]-(n-c2)*cy+(b[n-1]-b[c2-1]);
		cout<<r<<endl;
	}
	return 0;
}
		