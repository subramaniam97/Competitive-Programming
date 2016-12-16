#include<iostream>
#include<cmath>
using namespace std;

int main()
{
        int t,s,i,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		s=0;
		if(!(n&1))s=-(n>>1);
		else
		s=(n-(n>>1));
		cout<<s<<endl;
	}

	return 0;	
}