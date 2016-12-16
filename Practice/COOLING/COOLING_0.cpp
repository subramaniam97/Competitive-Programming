#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,a[100],b[100],c,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		i=0;
		c=0;
		for(j=0;j<n;j++)
		cin>>a[j];
		for(j=0;j<n;j++)
	    cin>>b[j];
		stable_sort(a,a+n);
		stable_sort(b,b+n);
		while(i!=n)
		{
			while(b[i]<a[c])
			{
			    
				i++;
				if(i==n)
				{
				    goto a;
				    
				}
				
			}
			c++;
			i++;
		}
		a:
		//free(a);
		//free(b);
		cout<<c<<endl;
	}
return 0;
}  