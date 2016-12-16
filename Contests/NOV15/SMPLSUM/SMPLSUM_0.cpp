#include<bits/stdc++.h>
#define MAX 10000001
using namespace std;

long long int b;
long long int spf[MAX];
bool primes[MAX];

long long int fast_exp(long long int b,long long int e)
{
    long long int res=1;
    while(e)
    {
        if(e&1)res*=b;
        b*=b;
        e>>=1;
    }
    return res;
}

void sieve()
{
    long long int i,j;
	for(i=2;i<=MAX;i+=2)spf[i]=2;
	for(i=3;i<=MAX;i+=2)
    {
		if(!primes[i])
		{
			spf[i]=i;
			for(j=i;(j*i)<=MAX;j+=2)
			{
				if(!primes[j*i])
                {
                    primes[j*i]=1;
                    spf[j*i]=i;
                }
			}
		}
	}
}

int main()
{
    long long int t,n,i,d,t1;
    sieve();
    spf[1]=1;
    scanf("%lld",&t1);
   while(t1--)
    {
            scanf("%lld",&n);
            i=n;
            b=1;
            while(i>1)
            {
                d=1;
                t=1;
                while(spf[i]==spf[i/spf[i]])
                {
                    i/=spf[i];
                    d++;
                }
                t+=((fast_exp(spf[i],2*d)-1)/(spf[i]+1))*spf[i];
                b*=t;
                i/=spf[i];
            }
            printf("%lld\n",b);

    }
    return 0;
}
