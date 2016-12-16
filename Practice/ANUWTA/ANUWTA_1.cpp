#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long int n;
    cin>>t;
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",((n*(n+1))>>1)+n);
    }
    return 0;
}