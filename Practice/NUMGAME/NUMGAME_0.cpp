#include<iostream>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(((float)n/2)==((int)n/2))printf("ALICE\n");
		else printf("BOB\n");
		
	}
	return 0;
}