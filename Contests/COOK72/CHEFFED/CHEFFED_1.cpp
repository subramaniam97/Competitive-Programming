#include<bits/stdc++.h>
using namespace std;

long long n;

long long s(long long x)
{
    long long r = 0;
    while(x)
    {
        r += (x % 10);
        x /= 10;
    }
    return r;
}

int main()
{
    cin>>n;
    int cnt = 0;
    for(long long i = max(0LL, n - 100); i <= n; i++)
    {
        if(i + s(i) + s(s(i)) == n)
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
