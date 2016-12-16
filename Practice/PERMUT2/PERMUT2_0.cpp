#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int i,n=1,*a,c;
	while(n)
	{
		c=1;
		cin>>n;
		if(n==0)break;
		a=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)cin>>a[i];
		for(i=0;i<n;i++)
		{	
			if(a[i]!=(i+1))
			{
				if(a[a[i]-1]!=(i+1))
				{
					c=0;
					break;
				}
			}	
		}
		if(c==1)cout<<"ambiguous"<<endl;
		else cout<<"not ambiguous"<<endl;
	}
return 0;
}