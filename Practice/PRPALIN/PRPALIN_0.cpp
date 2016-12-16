#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long int n,i,j=0,k,r;
	char a[10];
	int c;
	cin>>n;
	for(i=n;;i++)
	{
		r=i;
		j=0;
	    c=0;
        while(r)
        {
            a[j]=r%10;
		    r=r/10;
		    j++;
        }
        for(k=0;k<j/2;k++)
        {
            if(a[k]!=a[j-k-1])
            {
                    c=1;
                    break;
            }
        }
        
        if(c==0)
		{
			for(j=1;j<=sqrt(i);j++)
			{
				if(i%j==0)c++;
				if(c==2)break;
			}
			if(c==1)break;
		}
	}
	cout<<i;
	return 0;
}