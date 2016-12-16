#include<bits/stdc++.h>

using namespace std;

 

int main()

{

	int t,n,a[5000],i,m;

	cin>>t;

	while(t--)

	{

		cin>>n;

		for(i=0;i<n;i++)cin>>a[i];

		sort(a,a+n);

		m=a[1]-a[0];

		for(i=2;i<n;i++)

		{

			if(m>a[i]-a[i-1])m=a[i]-a[i-1];

		}

		cout<<m<<endl;	

	}

	return 0;

}

