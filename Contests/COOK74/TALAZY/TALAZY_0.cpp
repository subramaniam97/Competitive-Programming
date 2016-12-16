#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long n, b, m;
    cin>>t;
    while(t--)
    {
        long long r = 0;
        cin>>n>>b>>m;
        while(n)
        {
            r += ((ceil(n / 2.0)) * m);
            m *= 2;
            n /= 2;
            if(n)
                r += b;
        }
        cout<<r<<endl;
    }
    return 0;
}
