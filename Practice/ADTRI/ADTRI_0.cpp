#include<bits/stdc++.h>
using namespace std;
#define N 5000002

bool is_hyp[N];
bool is_prime[N];
vector<int> primes;

void preprocess()
{
    int i,j;
    for(i=2;i<=sqrt(N);i++)
    {
        if(is_prime[i])
        {
            if(i%4==1)primes.push_back(i);
              for(j=i;j*i<=N;j++)is_prime[j*i]=0;
        }
        
    }
    for(i=sqrt(N)+1;i<=N;i++)
    {
        if(is_prime[i])
        if(i%4==1)primes.push_back(i);
    }
    for(i=0;i<primes.size();i++)
    {
        is_hyp[primes[i]]=1;
        for(j=primes[i];j<=N;j=j+primes[i])
        {
            is_hyp[j]=1;
        }
    }
}

int main()
{
    int i,t,n;
    memset(is_hyp,0,sizeof(is_hyp));
    for(i=0;i<N;i++)is_prime[i]=1;
    preprocess();
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        i=is_hyp[n];
        if(i)printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}