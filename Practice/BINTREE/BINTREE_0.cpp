#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n,a,b,i,r1,r2,c[100005],k,p,j;
    
    cin>>n;
    for(i=0;i<n;i++)
    {
        
    	k=0,r1=0,r2=0,p=1;
    	cin>>a>>b;
    	if(a>b)
    	{
    		a=a^b;
    		b=a^b;
    		a=a^b;
    	}
    	while(1)
    	{
    	   for(j=0;j<k;j++)
    	    {
    	        if(b==c[j]){r1=j;goto a;}
    	    }
    	    c[k++]=a;
    	    a/=2;
    	    if(p!=1)
    	    {
    	    b/=2;
    	    r2++;
    	    }
    	    p=0;
    	    
    	}
    	a:
    	cout<<r1+r2<<endl;
    }
    return 0;
}
