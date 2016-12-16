#include<iostream>
using namespace std;
int main()
{
	int t,n,a[100],i,v,c,m,j;
	cin>>t;
	while(t--)
	{
		int b[10001]={0};
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			b[a[i]]++;
		}
		m=b[1];
		v=1;
		for(j=2;j<=10000;j++)
		{
			if(m<b[j])
			{
				m=b[j];
				c=m;
				v=j;
			}
			else if(m==b[j])
			{
				if(v>j)v=j;
				c=m;
			}
		}
	
		cout<<v<<" "<<c<<endl;
	}
		return 0;
}