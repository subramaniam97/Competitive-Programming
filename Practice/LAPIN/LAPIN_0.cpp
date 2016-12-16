#include<bits/stdc++.h>

#define y cout<<"YES\n";
#define n cout<<"NO\n";

using namespace std;

int main()
{
	int t,i,l;
	string s;
	cin>>t;
	while(t--)
	{
	        int a[26]={0},b[26]={0};
    	    cin>>s;
    	    l=s.length();
    	    for(i=0;i<(l/2);i++)
    	    {
    	        a[s[i]-97]++;
    	        b[s[l-i-1]-97]++;
    	    }
    	    for(i=0;i<26;i++)
    	    {
    	        if(a[i]!=b[i])break;
    	    }
    	    if(i==26)y
    	    else n
	}
	   return 0;
}