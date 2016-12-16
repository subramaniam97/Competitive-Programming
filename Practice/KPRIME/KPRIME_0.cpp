#include <iostream>
using namespace std;

int spf[100001];
bool primes[100001];
int ans[100001];

void pre()
{
    long long int i,j;
    spf[1]=1;
    for(i=2;i<100001;i=i+2)spf[i]=2;
    for(i=3;i<100001;i=i+2)
    {
        if(!primes[i])
        {
            spf[i]=i;
            for(j=i;(j*i)<100001;j=j+2)
            {
                if(!primes[i*j]) primes[i*j]=1, spf[j*i]=i;
            }
        }
    }
    for(i=1;i<100001;i++)
    {
        int d=0,j;
        j=i;
        while(j>1)
        {
            while(spf[j/spf[j]]==spf[j])j/=spf[j];
            d++;
            j/=spf[j];
        }
        ans[i]=d;
    }
}

int main() 
{
	int t,a,i,b,k,c;
	pre();
	cin>>t;
	while(t--)
	{
	    c=0;
	    cin>>a>>b>>k;
	    for(i=a;i<=b;i++)
	    {
	        if(ans[i]==k)c++;
	    }
	    cout<<c<<endl;
	}
	return 0;
}
