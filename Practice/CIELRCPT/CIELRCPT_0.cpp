#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t,p,n,i;
	cin>>t;
	while(t--)
	{
		n=0;
		i=0;
		cin>>p;
		a:
		if(p==0)goto b;
		i=log2(p);
		if(i<=11)
		{
		    n++;
		    p-=pow(2,i);
		}
		else
		{
		        while(i!=11)
		        {
		                n++;
		                i--;
		                p-=pow(2,11);
		        }
		}
		goto a;
		b:
		cout<<n<<endl;
	}
	return 0;
}