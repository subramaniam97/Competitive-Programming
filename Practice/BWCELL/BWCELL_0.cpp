#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    int t,i;
    string s;
    cin>>t;
    while(t--)
    {
	cin>>s;
	i=0;
	while(s[i]!='W')i++;
	(i==s.length()-i-1)?printf("Chef\n"):printf("Aleksa\n");
    }
    return 0;
}


// ^_^ \\