#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t,n,i,d,s,h,r,a[51],b[51],f=0,p,q;
	cin>>t;
	while(t--)
	{
		d=h=f=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			h+=a[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>b[i];
			d+=b[i];
		}
		if(n!=2)
		{
			s=(d-h)/(n-2);
			p=(d-h)%(n-2);
			if(s<0||p!=0)r=-1;
			else
			{
				for(i=0;i<n;i++)
				{
					if(a[i]+s-b[i]<0||(a[i]+s-b[i])%2!=0)
					{
						f=1;
						r=-1;
						break;
					}
				}
				if(!f)r=s;
			}
		}
		else
		{
			
			if((b[1]-a[1])!=(a[0]-b[0]))r=-1;
			else
			{
				r=fabs(b[1]-a[1]);
			}
		}
		cout<<r<<endl;
	}
	return 0;
}		