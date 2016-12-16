#include<bits/stdc++.h>
using namespace std;

bool primes[500001];
int spf[500001];
int root[500001];
int flag;

long long int fast_exp(long long int base,long long int exp)
{
    if(exp<=0)return 1;
    long long r=1;
    while(exp)
    {
        if(exp&1)r=r*base;
        if(base>=10000)flag=1,base%=10000;
        base=(base*base);
        exp>>=1;
        if(r>=10000)flag=1,r%=10000;
    }
    return r;
}

void preprocess()
{
    long long int i,j;
	for(i=2;i<=500000;i+=2)	spf[i] = 2;
		for (i=3;i<=500000;i+=2){
		if (!primes[i]){
			spf[i]=i;
			for (j=i;(j*i)<=500000;j+=2){
				if (!primes[j*i])	primes[j*i] = 1, spf[j*i] = i;
			}
		}
	}
	for(i=1;i*i<=500000;i++)
	{
        root[i*i]=i;
	}
}

long long int div(long long int n)
{
    long long int i,d,m=1;
    i=n;
    while(i>1)
    {
        d=1;
        while(spf[i/spf[i]]==spf[i])
        {
            d++;
            i/=spf[i];
        }
        i/=spf[i];
        d++;
        m*=d;
    }
    return m;
}

int main()
{
    int n,a,i;
    long long int m;
    preprocess();
    spf[1]=1;
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        scanf(" %d",&n);
        flag=0;
        m=div(n);
        if(!root[n])
        {
            a=fast_exp(n,(m-2)/2);
            if(!flag)
                printf("%d\n",a);
            else printf("%04d\n",a);
        }
        else
        {

            a=fast_exp(root[n],(m-2));
            if(!flag)
                printf("%d\n",a);
            else printf("%04d\n",a);
        }
    }
    return 0;
}
