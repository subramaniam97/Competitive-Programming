#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t,i,j,cnt;
	char c[6][10];
	cin>>t;
	while(t--)
	{
		for(i=0;i<6;i++)cin>>c[i];
		for(j=0;j<2;j++)
		{
		cnt=0;
		for(i=0;i<=2;i=i+2)
		{
		if(strcmp(c[i+2],c[j])==0||strcmp(c[i+3],c[j])==0)
		{
			cnt++;
			if(cnt==2)
			{
				cout<<"YES";
				goto a;
			}
		}	
		}
		}
		cout<<"NO";
		a:
		cout<<endl;
	}
	return 0;
}