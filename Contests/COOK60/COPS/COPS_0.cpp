#include<iostream>
using namespace std;

int main()
{
	int t,m,x,i,y,n,r,l,u,j,a;
	cin>>t;
	while(t--)
	{
		n=0;
		int h[100]={0};
		cin>>m>>x>>y;
		r=x*y;
		for(i=0;i<m;i++)
		{
			cin>>a;
			if((a+r)>100)u=100;
			else u=a+r;
			if((a-r)<1)l=1;
			else l=a-r;
			for(j=l;j<=u;j++)h[j-1]=-1;
		}
		for(i=0;i<100;i++)
		{
			if(h[i]==0)n++;
		}
		cout<<n<<endl;
	}
	return 0;
}