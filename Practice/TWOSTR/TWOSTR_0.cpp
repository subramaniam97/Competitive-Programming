#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,i=0,f=1;
	string a,b,r;
	cin>>t;
	while(t--)
	{
		i=0;
		f=1;
		cin>>a>>b;
		while((i!=a.length())&&(f==1))
		{
			if(a[i]!='?')
			{
				if(a[i]!=b[i]&&b[i]!='?')
				f=0;
			}
			i++;
		}
		if(f==0)r="No";
		else r="Yes";
		cout<<r<<endl;
	}
	return 0;
}

