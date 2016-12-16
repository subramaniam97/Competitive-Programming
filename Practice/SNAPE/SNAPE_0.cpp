#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int t;
	float b,ls;
	cin>>t;
	while(t--)
	{
		cin>>b>>ls;
		cout<<(float)sqrt(ls*ls-b*b)<<" "<<(float)sqrt(ls*ls+b*b);
		cout<<endl;
	}
	return 0;
}