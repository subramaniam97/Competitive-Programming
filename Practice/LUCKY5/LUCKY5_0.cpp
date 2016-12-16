#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,i,c;
    string a;
    cin>>t;
    while(t--)
    {
    	c=0;
	cin>>a;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!='4'&&a[i]!='7')c++;
	}
	cout<<c<<endl;
    }
    return 0;
}
