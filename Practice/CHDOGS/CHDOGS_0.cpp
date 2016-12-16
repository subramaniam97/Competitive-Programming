#include<bits/stdc++.h>
using namespace std;

double s, v, r;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s>>v;
        r = (s * 2) / (v * 3);
        printf("%.15lf\n", r);
    }
    return 0;
}