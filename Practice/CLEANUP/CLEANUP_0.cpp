#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
 
int main()
{
	int t,n,m,i,j,*a,b[1000],c[1000],k,p,q;
	cin>>t;
	while(t--)
	{
		k=0;
		p=0;
		q=0;
		cin>>n>>m;
		if(m!=0)
		{
		a=(int*)malloc(m*sizeof(int));
		for(i=0;i<m;i++)cin>>a[i];
		sort(a,a+m);
		}
		else
		{
		    a=(int*)malloc(sizeof(int));
		    a[0]=0;
		}
		for(i=1,j=1;i<=n;i++)
		{
			if(a[j-1]!=i)
			{
				if(k==0)
				{
					k++;
					b[p]=i;
					p++;
				}
				else
				{
					k--;
					c[q]=i;
					q++;
				}
			}
			else j++;
		}
		j=0;
		k=0;
		if(p==0)
		{
		        cout<<endl;
		        j=1;
		}
		
		if(j!=1)
		{
		    for(i=0;i<p-1;i++)cout<<b[i]<<" ";
		    cout<<b[p-1];
		    cout<<endl;
		}
		if(q==0)
		{
		        cout<<endl;
		        k=1;
		}
		if(k!=1)
		{
		    for(i=0;i<q-1;i++)cout<<c[i]<<" ";
		    cout<<c[q-1];
		    if(t!=0)
		    cout<<endl;
		}
		free(a);
	}
	return 0;
} 