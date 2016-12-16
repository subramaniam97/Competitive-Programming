#include<iostream>
using namespace std;
int main()
{
	int w;
	float ib;
	cin>>w;
	cin>>ib;
	if((w%5==5||w%5==0)&&(ib>=(w+0.50)))
	{	
		ib=ib-w-0.50;
		cout<<ib;
	}
	else
	{
	cout<<ib;
	}
	return 0;
}
