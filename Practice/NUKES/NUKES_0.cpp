#include<iostream>
using namespace std;
int main()
{
	int i,n,k,a,c,e;
	cin>>a>>n>>k;
	for(i=0;i<k;i++)
	{
	    c=a%(n+1);
	    e=a/(n+1);
	    a=e;
	    cout<<c<<" ";
	}
	return 0;
} 