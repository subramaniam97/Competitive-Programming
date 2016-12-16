#include <iostream>
#include <cmath>
#include <cstring>
#define ll long long int
using namespace std;
int mod;
ll gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

ll mod_exp(int base, int exp)
{
    if(mod==0)return 1;
    ll r=1;
    while(exp>0)
    {
        if(exp&1)r=((r%mod)*(base%mod))%mod;
        base=((base%mod)*(base%mod))%mod;
        exp>>=1;
    }
    return r;
}



int main()
{
	string s;
	int t,i,h;
	ll a;
	cin>>t;
	while(t--)
	{
	    a=0;
	    h=0;
	    cin>>mod;
	    cin>>s;
	    for(i=s.length()-1;i>=0;i--)
	    {
	        if(mod==0)break;
	        a+=((s[i]-48)*mod_exp(10,h++))%mod;
	        a=a%mod;
	    }
	    if(mod==0)cout<<s<<endl;
	    else
	    cout<<gcd(mod,a)<<endl;
	}
	
	return 0;
}
