#include<iostream>
using namespace std;

int main()
{
	int t,n;
	char a1,a2,a3;
	cin>>t;
	while(t--)
	{	
		cin>>n;
		if(n==0){cout<<"y y y"; cout<<endl; continue;}
		if(360%n==0){a1='y'; a2='y';}
		else a1='n';
		if(n<=26)a3='y';
		else a3='n';
		if(n<=360)a2='y';
		else a2='n';
		cout<<a1<<" "<<a2<<" "<<a3;
		cout<<endl;
	}
	return 0;
}
	