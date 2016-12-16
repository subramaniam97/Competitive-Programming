#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t,i,r;
	string s;
	cin>>t;
	while(t--)
	{
	       r=0;
	    int a[26]={0},b[26]={0};
	    cin>>s;
	    for(i=0;i<s.length();i++)
	    {
	        if(s[i]>=65&&s[i]<=90)a[s[i]-65]++;
	        else b[s[i]-97]++;
	    }
	   
	    for(i=0;i<26;i++)
	    {
	        r+=(int)ceil(float(a[i])/2);
	        r+=(int)ceil(float(b[i])/2);
	    }
	    cout<<r<<endl;
	}
	return 0;
}