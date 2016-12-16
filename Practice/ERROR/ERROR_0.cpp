#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,i,f;
    string s;
    cin>>t;
    while(t--)
    {
    f=0;
	cin>>s;
	if(s.length()==1||s.length()==2)goto a;
	for(i=0;i<s.length()-2;i++)
	{
		if((s[i]!=s[i+1])&&(s[i+1]!=s[i+2]))f=1;
	}
	a:
	if(f)
	cout<<"Good\n";
	else
	cout<<"Bad\n";
    }
    return 0;
}
