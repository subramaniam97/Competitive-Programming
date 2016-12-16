#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int t,l,i,j,k;
	cin>>t;
	while(t--)
	{
	   i=j=k=0;
		char a[401],b[401],c[401];
		cin>>a;
		l=strlen(a);
		while(1)
		{
			a:
			if(i==l)break;
			if((a[i]!='+')&&(a[i]!='-')&&(a[i]!='*')&&(a[i]!='/')&&(a[i]!='^')&&(a[i]!='(')&&(a[i]!=')'))
			{
				b[j]=a[i];
				j++;
                i++;
                goto a;
			}
		else if(a[i]=='(')
			{
				c[k]=a[i];
				k++;
				i++;
				goto a;
			}
			else if((a[i]=='+')||(a[i]=='*')||(a[i]=='-')||(a[i]=='/')||(a[i]=='^'))
			{
				c[k]=a[i];
				k++;
				i++;
				goto a;
			}
			else
			{
				while(c[k-1]!='(')
				{
					b[j]=c[k-1];
					j++;
					k--;
				}
				k--;
				i++;
				goto a;
			}	
				
		 }		
			b[j]='\0';
		cout<<b<<endl;
	}
	return 0;
}