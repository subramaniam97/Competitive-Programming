#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b;
	c=a-b;
	if(c%10!=9)c++;
	else c--;
	cout<<c;
	return 0;
} 